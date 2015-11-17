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
	
	param_list_resolve(p->next);
}
