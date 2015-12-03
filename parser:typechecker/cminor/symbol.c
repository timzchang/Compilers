#include "symbol.h"
#include "scope.h"
#include <string.h>

// extern error_count;

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
	struct symbol *s = malloc(sizeof(*s));
	s->kind = kind;
	s->type = type;
	s->name = name;  // for globals
	// which = ; how do we keep track ?
	s->which = 0;
	return s;
}

// compare symbols
int symbol_compare(struct symbol *a, struct symbol *b){
	if(!a && !b) return 1;
	if(!a || !b) return 0;
	if(a->name && b->name)
		return (a->kind == b->kind && a->which == b->which && strcmp(a->name, b->name) && a->code == b->code);
	else if(!a->name && !b->name)
		return (a->kind == b->kind && a->which == b->which && a->code == b->code);
	else
		return 0;
}



