#include "stmt.h"

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
			t = expr_typecheck(s->expr);
			if(t->kind != TYPE_BOOLEAN || t->kind != TYPE_VOID){
				printf("type error: expression in for loop (");
				expr_print(s->expr);
				printf(") must be either of type boolean or void\n");
				error_count++;
			}
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