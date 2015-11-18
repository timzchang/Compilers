#ifndef SCOPE_H
#define SCOPE_H 

#include "symbol.h"
#include "hash_table.h"
#include "global.h"

extern struct hash_table *h;

void scope_enter();  // when we see {, create a new hash_table and connect
void scope_leave();  // when we see }, go back one hash table and delete
int scope_level();  // lookup current level?
void scope_bind(const char * name, struct symbol *sym);  // insert into the current scope an entry binding a name to a symbol object
struct symbol * scope_lookup_single(const char * name);  // see if this symbol exists in this scope
struct symbol * scope_lookup(const char * name);

#endif
