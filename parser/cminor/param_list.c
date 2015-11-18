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
	
	if(scope_lookup_single(p->name)){
		printf("resolve error: %s already defined in this scope\n", p->name);
		error_count++;
	}else{
		struct symbol *sym = symbol_create(SYMBOL_PARAM, p->type, p->name);
		scope_bind(p->name, sym);
		printf("%s resolves to param %d", p->name, sym->which);
		p->symbol = sym;
	}
	param_list_resolve(p->next);
}
