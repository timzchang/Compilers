#include "param_list.h"

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ){
	struct param_list *p = malloc(sizeof(*p));
	p->name = name;
	p->type = type;
	p->symbol = NULL;  // for type-checking
	p->next = next;
	return p;
}

void param_list_print( struct param_list *p ){
	if(!p) return;
	printf("%s", p->name);
	printf(":");
	type_print(p->type);
	if(p->next){
		printf(", ");
		param_list_print(p->next);
	}
}

// have to store params in a place where they can be resolved in block.
void param_list_resolve(struct param_list *p){
	if(!p) return;
	/*if(e->kind == EXPR_NAME){
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
	}*/
	param_list_resolve(p->next);
}
