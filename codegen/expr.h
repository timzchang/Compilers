#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"
#include "scope.h"
#include "global.h"
// #include "type.h"
typedef enum {
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MULT,
	EXPR_DIV,
	EXPR_NAME,
	EXPR_STRING,
	EXPR_INT,
	EXPR_BOOLEAN,
	EXPR_CHAR,
	EXPR_ASSGN,
	EXPR_GT,
	EXPR_LT,
	EXPR_GE,
	EXPR_LE,
	EXPR_EQ,
	EXPR_NE,
	EXPR_NOT,
	EXPR_NEG,
	EXPR_EXP,
	EXPR_INCR,
	EXPR_DECR,
	EXPR_BRACKET,
	EXPR_FUNC,
	EXPR_LIST,
	EXPR_OR,
	EXPR_AND,
	EXPR_MOD,
	EXPR_BLOCK
	/* many more types to add here */
} expr_t;

struct expr {
	/* used by all expr types */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by leaf expr types */
	const char *name;
	struct symbol *symbol;
	int literal_value;
	const char * string_literal;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name( const char *n );
struct expr * expr_create_boolean_literal( int c );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_character_literal( int c );
struct expr * expr_create_string_literal( const char *str );

void expr_print( struct expr *e );
void expr_resolve(struct expr *e);
struct type * expr_typecheck(struct expr * e);
struct expr * expr_copy(struct expr *e);
int expr_compare(struct expr *a, struct expr *b);
int expr_is_constant(struct expr *a);
void expr_codegen(struct expr *a, char *output);

#endif
