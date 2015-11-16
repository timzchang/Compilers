
#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include "decl.h"
#include "param_list.h"
#include <stdlib.h>
typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	int which;
	struct type *type;
	char *name;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name );


#endif
