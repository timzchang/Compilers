#include "expr.h"
#include "type.h"
#include "register.h"
#include <string.h>

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ){
	struct expr *e = malloc(sizeof(*e));
	e->kind = kind;
	e->left = left;
	e->right = right;
	e->name = NULL;
	e->symbol = NULL;
	e->literal_value = 0;
	e->string_literal = NULL;
	e->reg = -1;
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
	e->reg = -1;
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
	e->reg = -1;
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
	e->reg = -1;
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
	e->reg = -1;
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
	e->reg = -1;
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
		printf("printing string\n");
		//printf("\"");
		int i;
		for(i=0; i<strlen(e->string_literal); i++){
			if(e->string_literal[i]==0){
				printf("\\0");
			}else if(e->string_literal[i]==0x0A){
				printf("\\n");
			}else{
				printf("%c",e->string_literal[i]);
			}
		}
		//printf("%s",e->string_literal);
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
		printf("printing char\n");
		if(e->literal_value == 0x0A)
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
	if(e->kind == EXPR_NAME){
		//s = scope_lookup(e->name);
		struct symbol *s = scope_lookup(e->name);
		if(s){
			printf("symbol set\n");
			e->symbol = s;
			if(e->symbol->kind == SYMBOL_LOCAL){
				printf("%s resolves to local %d\n", e->name, e->symbol->which);
			}else if(e->symbol->kind == SYMBOL_PARAM){
				printf("%s resolves to param %d\n", e->name, e->symbol->which);
			}else{
				printf("%s resolves to global %s\n", e->name, e->symbol->name);
			}
		}else{
			printf("resolve error: %s is not defined\n", e->name);
			error_count++;
		}
	}
}

//TODO: EXPR_FUNC
struct type * expr_typecheck(struct expr * e){
	if(!e) return type_create(TYPE_VOID, 0, 0, 0);
	struct type * L = expr_typecheck(e->left);
	struct type * R = expr_typecheck(e->right);
	struct symbol * sym;
	struct expr * e_cursor;
	struct param_list * p_cursor;
	int param_count = 0;
	int arg_count = 0;
	int counter = 0;
	switch(e->kind){
		case EXPR_ADD:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot add ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" to ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);  // assume the type for expressions
			break;
		case EXPR_SUB:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot subtract ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" from ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);  // assume the type for expressions
			break;
		case EXPR_MULT:
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot multiply ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" if ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);  // assume the type for expressions
			break;
		case EXPR_DIV:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot divide ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" with ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);  // assume the type for expressions
			break;
		case EXPR_NAME:
			return e->symbol->type;
			break;
		case EXPR_STRING:
			return type_create(TYPE_STRING, 0, 0, 0);
			break;
		case EXPR_INT:
			return type_create(TYPE_INTEGER, 0, 0, 0);
			break;
		case EXPR_BOOLEAN:
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_CHAR:
			return type_create(TYPE_CHARACTER, 0, 0, 0);
			break;
		case EXPR_ASSGN:
			//if(e->left->symbol){
				if(L->kind == TYPE_FUNCTION || R->kind == TYPE_FUNCTION){
					printf("type error: cannot assign ");
					type_print(e->left->symbol->type);
					printf(" (");
					expr_print(e->left);
					printf(")");
					printf(" to ");
					type_print(R);
					printf(" (");
					expr_print(e->right);
					printf(")");
					printf("\n");
					error_count++;
					return type_create(e->right->symbol->type->kind, 0, 0, 0);
				}
			// }
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(type_compare(L, R) == 0){
				printf("type error: cannot assign ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" to ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(R->kind, 0, 0, 0);
			break;
		case EXPR_GT:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_LT:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			//printf("I'm here\n");
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_GE:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_LE:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_EQ:
			// check if the types being compared as are functions or arrays
			/*if(e->left->kind == EXPR_BRACKET || e->left->kind == EXPR_FUNC || e->right->kind == EXPR_BRACKET || e->right->kind == EXPR_FUNC){
				printf("type error: cannot perform boolean logic on ");
				type_print(e->left->symbol->type);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(e->right->symbol->type);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
				return type_create(TYPE_BOOLEAN, 0, 0, 0);
			}*/
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != R->kind){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_NE:
			if(e->left->kind == EXPR_BRACKET || e->left->kind == EXPR_FUNC || e->right->kind == EXPR_BRACKET || e->right->kind == EXPR_FUNC){
				printf("type error: cannot perform boolean logic on ");
				type_print(e->left->symbol->type);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(e->right->symbol->type);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
				return type_create(TYPE_BOOLEAN, 0, 0, 0);
			}
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != R->kind){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_NOT:
			// // struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(R->kind != TYPE_BOOLEAN){
				printf("type error: cannot perform negation on");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_NEG:
			// struct type * R = expr_typecheck(e->right);
			if(R->kind != TYPE_INTEGER){
				printf("type error: cannot perform negation on");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);
			break;
		case EXPR_EXP:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot use exponent on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);
			break;
		case EXPR_INCR:
			// struct type * L = expr_typecheck(e->left);
			if(L->kind != TYPE_INTEGER){
				printf("type error: cannot increment ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);
			break;
		case EXPR_DECR:
			// struct type * L = expr_typecheck(e->left);
			if(L->kind != TYPE_INTEGER){
				printf("type error: cannot decrement ");
				type_print(L);
				printf("\n");
				printf(" (");
				expr_print(e->left);
				printf(")");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);
			break;
		case EXPR_BRACKET:
			// struct type * R = expr_typecheck(e->right);
			printf("type error: arrays are not supported\n");
			exit(1);
			/*
			if(R->kind != TYPE_INTEGER){
				printf("type error: cannot use ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf(" to index array");
				printf("\n");
				error_count++;
			}*/
			return type_create(e->left->symbol->type->kind, 0, e->left->symbol->type->subtype, e->left->symbol->type->opt_expr);
			break;
		case EXPR_FUNC:
			sym = scope_lookup(e->left->name);
			e_cursor = e->right;
			p_cursor = sym->type->params;
			while(e_cursor){  // code to traverse tree and increment arguments
				if(e_cursor->kind == EXPR_LIST){  // if the one we're on is exprlist
					if(e_cursor->right->kind != EXPR_LIST){  // and we're at thge end of our list
						arg_count += 2;  // add 2 
						break;
					}else{  // else add 1 and continue
						arg_count++;
						e_cursor = e_cursor->right;
					}
				}else{  // the one we're on is not exprlist, so add and leave
					arg_count++;
					break;
				}
			}
			while(p_cursor){
				param_count++;
				p_cursor = p_cursor->next;
			}
			if(param_count != arg_count){
				printf("type error: function (%s) needs %d arguments, got %d\n", e->left->name, param_count, arg_count);
				error_count++;
				return type_create(sym->type->subtype->kind, 0, 0, 0);
			}
			e_cursor = e->right;
			p_cursor = sym->type->params;
			if(arg_count == 1){
				if(!type_compare(expr_typecheck(e_cursor), p_cursor->type)){
					printf("type error: argument for function (%s) is of type ", e->left->name);
					type_print(expr_typecheck(e->right));
					printf(" but needs type ");
					type_print(p_cursor->type);
					printf("\n");
					error_count++;
				}
			}else{
				counter = 0;
				while(e_cursor){
					counter++;
					// there are more than one arguments, not at last 2
					if(e_cursor->right->kind == EXPR_LIST){
						if(!type_compare(expr_typecheck(e_cursor->left), p_cursor->type)){
							printf("type error: argument %d of function (%s) is of type ", counter, e->left->name);
							type_print(expr_typecheck(e_cursor->left));
							printf(" but needs type ");
							type_print(p_cursor->type);
							printf("\n");
							error_count++;
						}
					}else{  // at last 2 arguments. the left and right of EXPR_LIST are values
						if(!type_compare(expr_typecheck(e_cursor->left), p_cursor->type)){
							printf("type error: argument %d of function (%s) is of type ", counter, e->left->name);
							type_print(expr_typecheck(e_cursor->left));
							printf(" but needs type ");
							type_print(p_cursor->type);
							printf("\n");
							error_count++;
						}
						p_cursor = p_cursor->next;
						if(!type_compare(expr_typecheck(e_cursor->right), p_cursor->type)){
							printf("type error: argument %d of function (%s) is of type ", counter, e->left->name);
							type_print(expr_typecheck(e_cursor->left));
							printf(" but needs type ");
							type_print(p_cursor->type);
							printf("\n");
							error_count++;
						}
						e_cursor = 0;
					}
					if(e_cursor){
						e_cursor = e_cursor->right;
					}
					p_cursor = p_cursor->next;
				}
			}
			return type_create(sym->type->subtype->kind, 0, 0, 0);
			break;
		case EXPR_LIST:
			break;
		case EXPR_OR:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_BOOLEAN || R->kind != TYPE_BOOLEAN){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_AND:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_BOOLEAN || R->kind != TYPE_BOOLEAN){
				printf("type error: cannot perform boolean logic on ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" and ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_BOOLEAN, 0, 0, 0);
			break;
		case EXPR_MOD:
			// struct type * L = expr_typecheck(e->left);
			// struct type * R = expr_typecheck(e->right);
			if(L->kind != TYPE_INTEGER || R->kind != TYPE_INTEGER){
				printf("type error: cannot divide ");
				type_print(L);
				printf(" (");
				expr_print(e->left);
				printf(")");
				printf(" with ");
				type_print(R);
				printf(" (");
				expr_print(e->right);
				printf(")");
				printf("\n");
				error_count++;
			}
			return type_create(TYPE_INTEGER, 0, 0, 0);  // assume the type for expressions
			break;
		case EXPR_BLOCK:
			e_cursor = e->left;
			while(e_cursor){
				if(e_cursor->kind == EXPR_LIST){
					if(e_cursor->right->kind != EXPR_LIST){
						counter += 2;
						break;
					}else{
						counter++;
						e_cursor = e_cursor->right;
					}
				}else{
					counter++;
					break;
				}
			}
			return type_create(TYPE_ARRAY, 0, expr_typecheck(e->left->left), expr_create_integer_literal(counter));
			break;
		default:
			return type_create(TYPE_VOID, 0, 0, 0);
	}
	return type_create(TYPE_VOID, 0, 0, 0);
}

// function needed by type_copy()
struct expr * expr_copy(struct expr *e){
	if(!e) return NULL;
	struct expr * temp = malloc(sizeof(*e));
	char * name;
	char * string_literal;
	switch(e->kind){
		case EXPR_NAME:
			name = strdup(e->name);
			temp = expr_create_name(name);
			temp->symbol = scope_lookup(name);
			return temp;
			break;
		case EXPR_STRING:
			string_literal = strdup(e->string_literal);
			return expr_create_string_literal(string_literal);
			break;
		case EXPR_INT:
			return expr_create_integer_literal(e->literal_value);
			break;
		case EXPR_BOOLEAN:
			return expr_create_boolean_literal(e->literal_value);
			break;
		case EXPR_CHAR:
			return expr_create_character_literal(e->literal_value);
			break;
		default:
			return expr_create(e->kind, expr_copy(e->left), expr_copy(e->right));
	}
}

// compare two expr trees
int expr_compare(struct expr *a, struct expr *b){
	if(!a && !b) return 1;
	if(!a || !b) return 0;
	if(a->name && b->name){
		return (a->kind == b->kind && expr_compare(a->left, b->left) && 
		expr_compare(a->right, b->right) && strcmp(a->name, b->name) == 0 &&
		symbol_compare(a->symbol, b->symbol) && a->literal_value == b->literal_value);
	}else if(!a->name && !b->name){
		if(a->string_literal && b->string_literal){
			return (a->kind == b->kind && expr_compare(a->left, b->left) && 
				expr_compare(a->right, b->right) && symbol_compare(a->symbol, b->symbol) && 
				a->literal_value == b->literal_value && strcmp(a->string_literal, b->string_literal) == 0);
		}else if(!a->string_literal && !b->string_literal){
			return (a->kind == b->kind && expr_compare(a->left, b->left) && 
				expr_compare(a->right, b->right) && symbol_compare(a->symbol, b->symbol) && 
				a->literal_value == b->literal_value);
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int expr_is_constant(struct expr *a){
	if(!a) return 1;
	if(a->kind == EXPR_INT || a->kind == EXPR_BOOLEAN || a->kind == EXPR_CHAR || a->kind == EXPR_STRING){
		return 1;
	}else{
		return 0;
	}
	//return (expr_is_constant(a->left) && expr_is_constant(a->right));
}

void expr_codegen(struct expr *e, FILE *output){
	if(!e) return;
	char reg_name[200];
	char arg_reg[6][100] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
	int i;
	struct expr *e_cursor;
	switch(e->kind){
	case EXPR_ADD:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tADD %s, %s\n",register_name(e->left->reg), register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_SUB:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tSUB %s, %s\n",register_name(e->left->reg), register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_MULT:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tMOV %s, %%rax\n", register_name(e->left->reg));
		fprintf(output, "\tIMUL %s\n",register_name(e->right->reg));
		fprintf(output, "\tMOV %%rax, %s\n", register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_DIV:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tMOV %s, %%rax\n", register_name(e->left->reg));
		fprintf(output, "\tCQTO\n");
		fprintf(output, "\tIDIV %s\n",register_name(e->right->reg));
		fprintf(output, "\tMOV %%rax, %s\n", register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_NAME:
		e->reg = register_alloc();
		symbol_code(e->symbol, reg_name);
		fprintf(output, "\tMOV %s, %s\n", reg_name, register_name(e->reg));
		break;
	case EXPR_STRING:
		e->reg = register_alloc();
		fprintf(output, ".data\n");
		fprintf(output, ".STR%d:\n", str_count);
		fprintf(output, ".string"); 
		get_string(e, output);
		fprintf(output, "\n.text\n");
		fprintf(output, "LEA .STR%d, %s\n", str_count, register_name(e->reg));
		str_count++;
		break;
	case EXPR_INT:
		e->reg = register_alloc();
		fprintf(output, "\tMOV $%d, %s\n", e->literal_value, register_name(e->reg));
		break;
	case EXPR_BOOLEAN:
		e->reg = register_alloc();
		fprintf(output, "\tMOV $%d, %s\n", e->literal_value, register_name(e->reg));
		break;
	case EXPR_CHAR:
		e->reg = register_alloc();
		fprintf(output, "\tMOV $%d, %s\n", e->literal_value, register_name(e->reg));
		break;
	case EXPR_ASSGN:
		expr_codegen(e->right, output);
		symbol_code(e->left->symbol, reg_name);
		fprintf(output, "\tMOV %s, %s\n", register_name(e->right->reg), reg_name);
		e->reg = e->right->reg;
		break;
	case EXPR_GT:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
		fprintf(output, "\tJGE .L%d\n", label_count);
		label_count++;
		fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_count++;
		fprintf(output, ".L%d:\n", label_count-2);
		fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
		fprintf(output, ".L%d:\n", label_count-1);
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_LT:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
		fprintf(output, "\tJLE .L%d\n", label_count);
		label_count++;
		fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_count++;
		fprintf(output, ".L%d:\n", label_count-2);
		fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
		fprintf(output, ".L%d:\n", label_count-1);
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_GE:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
		fprintf(output, "\tJLE .L%d\n", label_count);
		label_count++;
		fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_count++;
		fprintf(output, ".L%d:\n", label_count-2);
		fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
		fprintf(output, ".L%d:\n", label_count-1);
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_LE:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
		fprintf(output, "\tJGE .L%d\n", label_count);
		label_count++;
		fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_count++;
		fprintf(output, ".L%d:\n", label_count-2);
		fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
		fprintf(output, ".L%d:\n", label_count-1);
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_EQ:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
		fprintf(output, "\tJE .L%d\n", label_count);
		label_count++;
		fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_count++;
		fprintf(output, ".L%d:\n", label_count-2);
		fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
		fprintf(output, ".L%d:\n", label_count-1);
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_NE:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tCMP %s, %s\n", register_name(e->left->reg), register_name(e->right->reg));
		fprintf(output, "\tJNE .L%d\n", label_count);
		label_count++;
		fprintf(output, "\tMOV $0, %s\n", register_name(e->right->reg));
		fprintf(output, "\tJMP .L%d\n", label_count);
		label_count++;
		fprintf(output, ".L%d:\n", label_count-2);
		fprintf(output, "\tMOV $1, %s\n", register_name(e->right->reg));
		fprintf(output, ".L%d:\n", label_count-1);
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_NOT:
		expr_codegen(e->right, output);
		fprintf(output, "\tXOR $1, %s\n", register_name(e->right->reg));
		e->reg = e->right->reg;
		break;
	case EXPR_NEG:
		expr_codegen(e->right, output);
		fprintf(output, "\tNEG %s\n", register_name(e->right->reg));
		//fprintf(output, "\tADD $1, %s\n", register_name(e->right->reg));
		e->reg = e->right->reg;
		break;
	case EXPR_EXP:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tPUSHQ %%rdi\n");
		fprintf(output, "\tPUSHQ %%rsi\n");
		fprintf(output, "\tPUSHQ %%r10\n");
		fprintf(output, "\tPUSHQ %%r11\n");
		fprintf(output, "\tMOV %s, %%rdi\n", register_name(e->left->reg));
		fprintf(output, "\tMOV %s, %%rsi\n", register_name(e->right->reg));
		fprintf(output, "\tCALL integer_power\n");
		fprintf(output, "\tPOPQ %%r11\n");
		fprintf(output, "\tPOPQ %%r10\n");
		fprintf(output, "\tPOPQ %%rsi\n");
		fprintf(output, "\tPOPQ %%rdi\n");
		fprintf(output, "\tMOV %%rax, %s\n", register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_INCR:
		expr_codegen(e->left, output);
		e->reg = e->left->reg;
		fprintf(output, "\tADD $1, %s\n", register_name(e->left->reg));
		symbol_code(e->left->symbol,reg_name);
		fprintf(output, "\tMOV %s, %s\n", register_name(e->left->reg), reg_name);
		break;
	case EXPR_DECR:
		expr_codegen(e->left, output);
		e->reg = e->left->reg;
		fprintf(output, "\tSUB $1, %s\n", register_name(e->left->reg));
		symbol_code(e->left->symbol,reg_name);
		fprintf(output, "\tMOV %s, %s\n", register_name(e->left->reg), reg_name);
		break;
	case EXPR_FUNC:
		e->reg = register_alloc();
		fprintf(output, "\tPUSHQ %%r10\n");
		fprintf(output, "\tPUSHQ %%r11\n");
		if(e->right && e->right->kind != EXPR_LIST){
			expr_codegen(e->right, output);
			fprintf(output, "\tMOV %s, %%rdi\n", register_name(e->right->reg));
			arg_count++;
			register_free(e->right->reg);
		}else{
			expr_codegen(e->right, output);
		}
		fprintf(output, "\tCALL %s\n", e->left->name);
		for(i = arg_count-1;i>=0; i--){
			fprintf(output, "\tPOPQ %s\n", arg_reg[i]);
		}
		fprintf(output, "\tPOPQ %%r11\n");
		fprintf(output, "\tPOPQ %%r10\n");
		fprintf(output, "\tMOV %%rax, %s\n", register_name(e->reg));
		break;
	case EXPR_LIST:  // function calls and prints
		e_cursor = e;
		while(e_cursor->right->kind == EXPR_LIST){
			//generate push code
			// increment counter
		}
		break;
	case EXPR_OR:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tOR %s, %s\n",register_name(e->left->reg), register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_AND:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tAND %s, %s\n",register_name(e->left->reg), register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_MOD:
		expr_codegen(e->left, output);
		expr_codegen(e->right, output);
		fprintf(output, "\tMOV %s, %%rax\n", register_name(e->left->reg));
		fprintf(output, "\tCQTO\n");
		fprintf(output, "\tIDIV %s\n",register_name(e->right->reg));
		fprintf(output, "\tMOV %%rdx, %s\n", register_name(e->right->reg));
		e->reg = e->right->reg;
		register_free(e->left->reg);
		break;
	case EXPR_BLOCK:

		break;
	}
}

void get_string(struct expr *e, FILE *output){
	//fprintf(output, "\"");
	int i;
	for(i=0; i<strlen(e->string_literal); i++){
		if(e->string_literal[i]==0){
			fprintf(output,"\\0");
		}else if(e->string_literal[i]==0x0A){
			fprintf(output,"\\n");
		}else{
			fprintf(output,"%c",e->string_literal[i]);
		}
	}
}

void expr_print_codegen(struct expr *e, FILE *output){
	struct type *t;
	expr_codegen(e, output);
	t = expr_typecheck(e);
	char name[200];
	//printf("%d\n", t->kind);
	switch(t->kind){
		case TYPE_INTEGER:
			sprintf(name, "integer");
			break;
		case TYPE_BOOLEAN:
			sprintf(name, "boolean");
			break;
		case TYPE_CHARACTER:
			sprintf(name, "character");
			break;
		case TYPE_STRING:
			sprintf(name, "string");
			break;
		default:
			printf("Error: expression unprintable\n");
			exit(1);
	}

	fprintf(output, "\tPUSHQ %%rdi\n");
	fprintf(output, "\tPUSHQ %%r10\n");
	fprintf(output, "\tPUSHQ %%r11\n");
	fprintf(output, "\tMOV %s, %%rdi\n", register_name(e->reg));

	fprintf(output, "\tCALL print_%s\n", name);
	
	fprintf(output, "\tPOPQ %%r11\n");
	fprintf(output, "\tPOPQ %%r10\n");
	fprintf(output, "\tPOPQ %%rdi\n");
	register_free(e->reg);
}

