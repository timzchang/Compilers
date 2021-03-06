#include "stmt.h"
//#include "register.h"

struct stmt * stmt_create( stmt_kind_t kind, struct decl *d, struct expr *init_expr, struct expr *e, struct expr *next_expr, struct stmt *body, struct stmt *else_body ){
	struct stmt *s = malloc(sizeof(*s));
	s->kind = kind;		
	s->decl = d;	
	s->init_expr=init_expr;	
	s->expr = e;	
	s->next_expr = next_expr;	
	s->body = body;	
	s->else_body = else_body;	
	s->next = NULL;
	return s;
}

void stmt_print( struct stmt *s, int indent ){
	if(!s) return;
	// printf("\n");
	switch(s->kind){
	case STMT_DECL:
		printf("\n");
		decl_print(s->decl, indent);
		break;
	case STMT_EXPR:
		printf("\n");
		printf("%*s",indent,"");
		expr_print(s->expr);
		printf(";");
		break;
	case STMT_IF_ELSE:
		printf("\n");
		printf("%*s",indent,"");
		printf("if (");
		expr_print(s->expr);
		printf(")");
		if(s->body && s->body->kind == STMT_BLOCK){  // if there is a stmt_block after the if
			printf(" {");
			stmt_print(s->body, indent);
			printf("\n%*s",indent,"");
			printf("}");
		}else{
			stmt_print(s->body, indent+4);  // if there's not just print the stmt
		}
		if(s->else_body && s->else_body->kind == STMT_BLOCK){
			printf(" else {");
			stmt_print(s->else_body, indent);
			printf("\n%*s",indent,"");
			printf("}");
		}else if(s->else_body){  // if there's an else_body but not a block
			printf(" else ");
			stmt_print(s->else_body, indent+4);
		}
		break;
	case STMT_FOR:
		printf("\n");
		printf("%*s",indent,"");
		printf("for(");
		expr_print(s->init_expr);
		printf(";");
		expr_print(s->expr);
		printf(";");
		expr_print(s->next_expr);
		printf(")");
		if(s->body && s->body->kind == STMT_BLOCK){
			printf(" {");
			stmt_print(s->body, indent+4);
			printf("\n%*s",indent,"");
			printf("}");
		}else{
			stmt_print(s->body, indent+4);
		}
		break;
	case STMT_PRINT:
		printf("\n");
		printf("%*s",indent,"");
		printf("print ");
		expr_print(s->expr);
		printf(";");
		break;
	case STMT_RETURN:
		printf("\n");
		printf("%*s",indent,"");
		printf("return ");
		expr_print(s->expr);
		printf(";");
		break;
	case STMT_BLOCK:
		// printf("%*s",indent,"");
		// printf("{\n");
		stmt_print(s->body, indent+4);
		// printf("\n%*s",indent,"");
		// printf("}");
		break;
	case STMT_EMPTY:
		break;
	}
	// printf("\n");
	stmt_print(s->next, indent);
}

void stmt_resolve(struct stmt *s){
	if(!s) return;
	switch(s->kind){
		case STMT_DECL:
			decl_resolve(s->decl);
			break;
		case STMT_EXPR:
			//printf("resolving a=s=10;\n");
			expr_resolve(s->expr);
			break;
		case STMT_IF_ELSE:
			// what if there's only one line in the body? then there's no block and no scope change...
			expr_resolve(s->expr);
			stmt_resolve(s->body);
			stmt_resolve(s->else_body);
			break;
		case STMT_FOR:
			expr_resolve(s->init_expr);
			expr_resolve(s->expr);
			expr_resolve(s->next_expr);
			stmt_resolve(s->body);
			break;
		case STMT_PRINT:
			expr_resolve(s->expr);
			break;
		case STMT_RETURN:  
			expr_resolve(s->expr);
			break;
		case STMT_BLOCK:
			scope_enter();
			stmt_resolve(s->body);
			scope_leave();
			break;
		case STMT_EMPTY:
			break;
	}
	stmt_resolve(s->next);
}

void stmt_typecheck(struct stmt *s, struct decl *d){
	if(!s) return;
	struct type *t;
	switch(s->kind){
		case STMT_DECL:
			if(s->decl->type->kind == TYPE_FUNCTION){
				printf("type error: cannot declare function (%s) within another function (%s)\n", s->decl->name, d->name);
				error_count++;
			}else{
				decl_typecheck(s->decl);
			}
			break;
		case STMT_EXPR:
			expr_typecheck(s->expr);
		break;
		case STMT_IF_ELSE:
			t = expr_typecheck(s->expr);
			if(t->kind != TYPE_BOOLEAN){
				printf("type error: If statement condition (");
				expr_print(s->expr);
				printf(") is not type boolean\n");
				error_count++;
			}
			stmt_typecheck(s->body, d);
			stmt_typecheck(s->else_body, d);
		break;
		case STMT_FOR:
			expr_typecheck(s->init_expr);
			t = expr_typecheck(s->expr);
			//printf("%d\n", t->kind);
			if(t->kind != TYPE_BOOLEAN && t->kind != TYPE_VOID){
				printf("type error: expression in for loop (");
				expr_print(s->expr);
				printf(") must be either of type boolean or void\n");
				error_count++;
			}
			expr_typecheck(s->next_expr);
			stmt_typecheck(s->body, d);
		break;
		case STMT_PRINT:
			expr_typecheck(s->expr);
		break;
		case STMT_RETURN:
			t = expr_typecheck(s->expr);
			if(t->kind != d->type->subtype->kind){
				printf("type error: expected return type of (%s) is ", d->name);
				type_print(d->type->subtype);
				printf(", got ");
				type_print(t);
				printf(" instead\n");
				error_count++;
			}
		break;
		case STMT_BLOCK:
			stmt_typecheck(s->body, d);
		break;
		case STMT_EMPTY:
		break;
	}
	stmt_typecheck(s->next, d);
}

void stmt_codegen(struct stmt *s, FILE *output){
	if(!s) return;
	int label_save, label_save1;
	struct expr *e_cursor;
	switch(s->kind){
	case STMT_DECL:
		decl_codegen(s->decl, output);
		break;
	case STMT_EXPR:
		expr_codegen(s->expr, output);
		register_free(s->expr->reg);
		break;
	case STMT_IF_ELSE:
		expr_codegen(s->expr, output);
		fprintf(output, "\tCMP $0, %s\n", register_name(s->expr->reg));
		register_free(s->expr->reg);
		fprintf(output, "\tJE .L%d\n", label_count);
		label_save = label_count;
		label_count++;
		stmt_codegen(s->body, output);
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_save1 = label_count;
		label_count++;
		fprintf(output, ".L%d:\n", label_save);
		stmt_codegen(s->else_body, output);
		fprintf(output, ".L%d:\n", label_save1);
		
		break;
	case STMT_FOR:
		expr_codegen(s->init_expr, output);  // i = something
		if(s->init_expr)
			register_free(s->init_expr->reg);
		fprintf(output, ".L%d:\n", label_count);  // this is the L we jump back to
		label_save = label_count;
		label_count++;
		expr_codegen(s->expr, output);  // (i<10) or something
		if(s->expr){
			register_free(s->expr->reg);
			fprintf(output, "\tCMP $0, %s\n", register_name(s->expr->reg));  // 
			fprintf(output, "\tJE .L%d\n", label_count);
		}
		label_save1 = label_count;
		label_count++;
		// stuff
		stmt_codegen(s->body, output);  // labelcount can be incremented in here
		// end stuff
		expr_codegen(s->next_expr, output);
		if(s->next_expr)
			register_free(s->next_expr->reg);
		fprintf(output, "\tJMP .L%d\n", label_save);
		fprintf(output, ".L%d:\n", label_save1);
		break;
	case STMT_PRINT:
		//printf("I'm here\n");
		if(s->expr){
			if(s->expr->kind!=EXPR_LIST){  // if the thing is a single expr
				//printf("Single expr\n");
				expr_print_codegen(s->expr, output);
			}else{
				//printf("multiple expr\n");
				e_cursor = s->expr;
				//expr_print(e_cursor->left);
				//printf("\n");
				//expr_print(e_cursor->right);
				while(e_cursor->right->kind == EXPR_LIST){
				//	printf("more exprs\n");
					expr_print_codegen(e_cursor->left, output);
					e_cursor = e_cursor->right;
				}
				expr_print_codegen(e_cursor->left, output);
				expr_print_codegen(e_cursor->right, output);
			}
		}else{
			// do nothing
		}
		break;
	case STMT_RETURN:
		if(s->expr){
			expr_codegen(s->expr, output);
			fprintf(output, "\tMOV %s, %%rax\n", register_name(s->expr->reg));
			// need return statement. Do we just label the postamble always?
			register_free(s->expr->reg);
			fprintf(output, "\tjmp .RET%d\n", ret_count);
		}else{
			fprintf(output, "\tjmp .RET%d\n", ret_count);
		}
		break;
	case STMT_BLOCK:
		stmt_codegen(s->body, output);
		break;
	default:
		printf("why am I here\n");
	}
	stmt_codegen(s->next, output);
}
