
#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"
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

void expr_resolve(struct expr *e);
void stmt_resolve(struct stmt *s);
void decl_resolve(struct decl *d);
void param_list_resolve(struct param_list *p);

#endif
