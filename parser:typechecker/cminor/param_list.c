#include "param_list.h"
#include <string.h>

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
		int *which = hash_table_lookup(h,"0params");  // which grabs the number of locals from the hash table
		struct symbol *sym = symbol_create(SYMBOL_PARAM, p->type, p->name);
		sym->which = *which;
		*which += 1;
		scope_bind(p->name, sym);
		p->symbol = sym;
		printf("%s resolves to param %d\n", p->name, sym->which);
	}
	param_list_resolve(p->next);
}

struct param_list * param_list_copy(struct param_list *p){
	if(!p) return NULL;
	struct param_list * temp = param_list_create(p->name, type_copy(p->type), param_list_copy(p->next));
	temp->symbol = scope_lookup(p->name);
	return temp;
}

//compare the two parameters
int param_list_compare(struct param_list *a, struct param_list *b){
	if(!a && !b) return 1;
	if(!a || !b) return 0;
	if(a->name && b->name)
		return (strcmp(a->name, b->name) == 0 && type_compare(a->type, b->type) && 
			symbol_compare(a->symbol, b->symbol) && param_list_compare(a->next, b->next));
	else if(!a->name && !b->name)
		return (type_compare(a->type, b->type) && symbol_compare(a->symbol, b->symbol) && 
			param_list_compare(a->next, b->next));
	else return 0;
}
