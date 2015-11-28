#include "scope.h"


//extern h;

// when we see {, create a new hash_table and connect
void scope_enter(){
	int * params = malloc(sizeof(int));
	int * locals = malloc(sizeof(int));
	*params = 0;
	*locals = 0;
	struct hash_table *h_prev;  // keep track of prev
	h->next = hash_table_create(0,0);  // create new hash table
	h_prev = h;  
	h = h->next;
	h->prev = h_prev;
	// hash_table_insert(h, "0next", hash_table_create(0,0));  // next pointer

	// h = hash_table_lookup(h, "0next");  // shift
	// hash_table_insert(h,"0prev", h_prev);  // now new table has a reverse pointer
	hash_table_insert(h,"0params", params);  // insert params and locals counter
	hash_table_insert(h,"0locals", locals);
}

// when we see }, go back one hash table and delete
void scope_leave(){
	// include check for null?
	// h = hash_table_lookup(h, "0prev");  // move h back
	h = h->prev;  // move h back
	hash_table_clear(h->next);
	hash_table_delete(h->next);
	h->next = NULL;
	// hash_table_clear(hash_table_lookup(h,"0next"));  // clear
	// hash_table_delete(hash_table_lookup(h,"0next"));  // delete table
} 

// lookup current level?
int scope_level(){
	int count=0;
	struct hash_table *h_cursor = h;
	while(h_cursor != NULL){
		h_cursor = hash_table_lookup(h_cursor, "0prev");
		count++;
	}
	return count;
}

// insert into the current scope an entry binding a name to a symbol object
void scope_bind(const char * name, struct symbol *sym){
	hash_table_insert(h, name, sym);
}  

struct symbol * scope_lookup_single(const char * name){
	return hash_table_lookup(h, name);
}

//traverse up the thing
struct symbol * scope_lookup(const char * name){
	struct hash_table *h_cursor = h;
	while(h_cursor){
		if(hash_table_lookup(h_cursor,name)){
			return hash_table_lookup(h_cursor,name);
		}
		h_cursor = hash_table_lookup(h_cursor, "0prev");
	}
	return NULL;
}
