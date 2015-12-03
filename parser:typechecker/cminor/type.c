#include "type.h"

struct type * type_create( type_kind_t kind, struct param_list *params, struct type *subtype, struct expr *opt_expr ){
	struct type *t = malloc(sizeof(*t));
	t->kind = kind;
	t->params = params;
	t->subtype = subtype;
	t->opt_expr = opt_expr;
	return t;
}

void type_print( struct type *t ){
	if(!t) return;
	switch(t->kind){
	case TYPE_BOOLEAN:
		printf("boolean");
		break;
	case TYPE_CHARACTER:
		printf("char");
		break;
	case TYPE_INTEGER:
		printf("integer");
		break;
	case TYPE_STRING:
		printf("string");
		break;
	case TYPE_ARRAY:
		printf("array [");
		expr_print(t->opt_expr);
		printf("] ");
		type_print(t->subtype);
		break;
	case TYPE_FUNCTION:
		printf("function ");
		type_print(t->subtype);
		printf("( ");
		param_list_print(t->params);
		printf(" )");
		break;
	case TYPE_VOID:
		printf("void");
		break;
	}
}

// recursively copy all the way down.
struct type * type_copy(struct type *t){
	if(!t) return NULL;
	struct type * temp = type_create(t->kind, param_list_copy(t->params), type_copy(t->subtype), expr_copy(t->opt_expr));
	return temp;
}

// compare two types
int type_compare( struct type *a, struct type *b ){
	if(!a && !b) return 1;
	if(!a || !b) return 0;
	return (a->kind == b->kind && param_list_compare(a->params, b->params) && 
		type_compare(a->subtype, b->subtype) && expr_compare(a->opt_expr, b->opt_expr));
}

// 
void type_delete( struct type *t ){

}