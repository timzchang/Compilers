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
	}
	// printf("\n");
	stmt_print(s->next, indent);
}