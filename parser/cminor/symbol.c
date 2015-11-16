#include "symbol.h"
#include "scope.h"

extern error_count;

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ){
	kind = kind;
	type = type;
	name = name;  // for globals
	// which = ; how do we keep track ?
}






