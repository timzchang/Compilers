#include "symbol.h"
#include "scope.h"

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






