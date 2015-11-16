#include "symbol.h"
#include "scope.h"

extern error_count;

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
	kind = kind;
	type = type;
	name = name;  // for globals
	// which = ; how do we keep track ?
}

void expr_resolve(struct expr *e){
	if(!e) return;
	expr_resolve(e->left);
	expr_resolve(e->right);
	struct symbol *s;
	if(e->kind == EXPR_NAME){
		s = scope_lookup(e->name);
		if(s){
			e->symbol = s;
			if(e->symbol->kind = SYMBOL_LOCAL){
				printf("%s resolves to local %d\n", e->name, e->symbol->which);
			}else if(e->symbol->kind = SYMBOL_PARAM){
				printf("%s resolves to param %d\n", e->name, e->symbol->which);
			}else{
				printf("%s resolves to global %s\n", e->name, e->symbol->name);
			}
		}else{
			printf("resolve error: %s is not defined", e->name);
			error_count++;
		}
	}
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
	}
}

void decl_resolve(struct decl *d){
	if(!d) return;
	struct symbol *sym = symbol_create(SYMBOL_GLOBAL, d->type, d->name);

}

// have to store params in a place where they can be resolved in block.
void param_list_resolve(struct param_list *p){
	if(!p) return;
	if(e->kind == EXPR_NAME){
		s = scope_lookup(e->name);
		if(s){
			e->symbol = s;
			if(e->symbol->kind = SYMBOL_LOCAL){
				printf("%s resolves to local %d\n", e->name, e->symbol->which);
			}else if(e->symbol->kind = SYMBOL_PARAM){
				printf("%s resolves to param %d\n", e->name, e->symbol->which);
			}else{
				printf("%s resolves to global %s\n", e->name, e->symbol->name);
			}
		}else{
			printf("resolve error: %s is not defined", e->name);
			error_count++;
		}
	}
	param_list_resolve(p->next);
}