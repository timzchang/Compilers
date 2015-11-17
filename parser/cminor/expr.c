#include "expr.h"
#include "symbol.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = kind;
	e->left = left;
	e->right = right;
	e->name = NULL;
	e->symbol = NULL;
	e->literal_value = 0;
	e->string_literal = NULL;
	return e;
}

struct expr * expr_create_name( const char *n ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = EXPR_NAME;
	e->left = NULL;
	e->right = NULL;
	e->name = n;
	e->symbol = NULL;
	e->literal_value = 0;
	e->string_literal = NULL;
	return e;
}

struct expr * expr_create_boolean_literal( int c ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = EXPR_BOOLEAN;
	e->left = NULL;
	e->right = NULL;
	e->name = NULL;
	e->symbol = NULL;
	e->literal_value = c;
	e->string_literal = NULL;
	return e;
}

struct expr * expr_create_integer_literal( int c ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = EXPR_INT;
	e->left = NULL;
	e->right = NULL;
	e->name = NULL;
	e->symbol = NULL;
	e->literal_value = c;
	e->string_literal = NULL;
	return e;
}
struct expr * expr_create_character_literal( int c ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = EXPR_CHAR;
	e->left = NULL;
	e->right = NULL;
	e->name = NULL;
	e->symbol = NULL;
	e->literal_value = c;
	e->string_literal = NULL;
	return e;
}

struct expr * expr_create_string_literal( const char *str ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = EXPR_STRING;
	e->left = NULL;
	e->right = NULL;
	e->name = NULL;
	e->symbol = NULL;
	e->literal_value = 0;
	e->string_literal = str;
	return e;
}

void expr_print( struct expr *e ){
	if(!e) return;
	if(!(e->literal_value || e->string_literal || e->name || e->kind == EXPR_FUNC || e->kind == EXPR_BRACKET || e->kind == EXPR_ASSGN || e->kind == EXPR_LIST))
		printf("(");
	// if(e->kind==EXPR_INT)
		// printf("(");
	expr_print(e->left);
	switch(e->kind){
	case EXPR_ADD:
		printf("+");
		break;
	case EXPR_SUB:
		printf("-");
		break;
	case EXPR_MULT:
		printf("*");
		break;
	case EXPR_DIV:
		printf("/");
		break;
	case EXPR_NAME:
		printf("%s",e->name);
		break;
	case EXPR_STRING:
		printf("%s",e->string_literal);
		break;
	case EXPR_INT:
		printf("%d",e->literal_value);
		break;
	case EXPR_BOOLEAN:
		if(e->literal_value)
			printf("true");
		else
			printf("false");
		break;
	case EXPR_CHAR:
		if(e->literal_value == 0x0aA)
			printf("%s", "\'\\n\'");
		else
			printf("\'%c\'", e->literal_value);
		break;
	case EXPR_ASSGN:
		printf("=");
		break;
	case EXPR_GT:
		printf(">");
		break;
	case EXPR_LT:
		printf("<");
		break;
	case EXPR_GE:
		printf(">=");
		break;
	case EXPR_LE:
		printf("<=");
		break;
	case EXPR_EQ:
		printf("==");
		break;
	case EXPR_NE:
		printf("!=");
		break;
	case EXPR_NOT:
		printf("!");
		break;
	case EXPR_NEG:
		printf("-");
		break;
	case EXPR_EXP:
		printf("^");
		break;
	case EXPR_INCR:
		printf("++");
		break;
	case EXPR_DECR:
		printf("--");
		break;
	case EXPR_BRACKET:
		printf("[");
		break;
	case EXPR_FUNC:
		printf("(");
		break;
	case EXPR_LIST:
		printf(",");
		break;
	case EXPR_OR:
		printf("||");
		break;
	case EXPR_AND:
		printf("&&");
		break;
	case EXPR_MOD:
		printf("%c",'%');
		break;
	}
	expr_print(e->right);
	if(!(e->literal_value || e->string_literal || e->name || e->kind == EXPR_FUNC || e->kind == EXPR_BRACKET || e->kind == EXPR_ASSGN || e->kind == EXPR_LIST))
		printf(")");
	if(e->kind==EXPR_FUNC)
		printf(")");
	else if(e->kind==EXPR_BRACKET)
		printf("]");
	// else if(e->kind==EXPR_INT)
		// printf(")");
	// printf(")");
}

void expr_resolve(struct expr *e){
	if(!e) return;
	expr_resolve(e->left);
	expr_resolve(e->right);
	struct symbol *s = scope_lookup(e->name);
	if(e->kind == EXPR_NAME){
		//s = scope_lookup(e->name);
		if(s){
			e->symbol = s;
			if(e->symbol->kind == SYMBOL_LOCAL){
				printf("resolution error: %s resolves to local %d\n", e->name, e->symbol->which);
			}else if(e->symbol->kind == SYMBOL_PARAM){
				printf("resolution error: %s resolves to param %d\n", e->name, e->symbol->which);
			}else{
				printf("resolution error: %s resolves to global %s\n", e->name, e->symbol->name);
			}
		}else{
			printf("resolve error: %s is not defined", e->name);
			error_count++;
		}
	}
}
