#include "decl.h"

struct decl * decl_create( char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next ){
	struct decl *d = malloc(sizeof(*d));
	d->name = name;
	d->type = t;
	d->value = v;
	d->code = c;
	d->symbol = NULL;
	d->next = next;
	return d;
}


/*
	char *name;  // ident. always have one
	struct type *type;  // type - print-type. always have one
	struct expr *value;  // either x: integer = >>5 - this portion<<; or x: array[3] = >>{1,2,3} - this portion<<;
	struct stmt *code;	// foo: function integer (bar: integer) = >>{stmt_list} - this portion<<;
	struct symbol *symbol;  // for type-checking only
	struct decl *next;	// next pointer
*/
void decl_print( struct decl *d, int indent ){
	if(!d) return;
	// printf("\n");
	printf("%*s",indent,"");
	printf("%s: ", d->name);
	type_print(d->type);
	if(d->value){
		printf(" = ");
		if(d->type->kind == TYPE_ARRAY){  // if value is {foo, bar, xxyzy}
			printf("{");
			expr_print(d->value);
			printf("}");
		}else{
			expr_print(d->value);
		}
		printf(";");
	}else if(d->code && d->code->kind == STMT_BLOCK){
		printf(" = ");
		printf("{");  // STMT_PRINT PRINTS \N FIRST ALWAYS
		stmt_print(d->code, indent+4);
		printf("\n%*s",indent,"");
		printf("}");
	}else{
		printf(";");
	}
	// printf("\n");
	decl_print(d->next, indent);
}

void decl_resolve(struct decl *d){
	if(!d) return;

	// so hear we need to do something to add something to the symbol table

	struct symbol *sym;
	sym = scope_lookup_single(d->name);
	if(sym){
		printf("resolve error: %s already defined in this scope\n", d->name);
		error_count++;
	}else{
		symbol_t kind;
		if(scope_level() == 1){
			kind = SYMBOL_GLOBAL;
			sym = symbol_create(kind, d->type, d->name);
			printf("%s resolves to global %s\n", d->name, sym->name);
		}else{
			kind = SYMBOL_LOCAL;
			sym = symbol_create(kind, d->type, d->name);
			sym->which = 1;
			printf("%s resolves to local %d\n", d->name, sym->which);
		}

		scope_bind(d->name, sym);
		d->symbol = sym;
		expr_resolve(d->value);
		if(d->code){
			scope_enter();
			param_list_resolve(d->type->params);
			stmt_resolve(d->code);
			scope_leave();
		}
		
	}
	decl_resolve(d->next);
}


void decl_typecheck(struct decl *d){
	if(!d) return;
	struct type *t = expr_typecheck(d->value);
	if(type_compare(d->type, t) != 0){
		// error_print(d->type, t);  // this will print the relevant typechecking error
	}
	if(d->value){
		if(d->symbol->kind == SYMBOL_GLOBAL && d->value->kind != EXPR_BOOLEAN && d->value->kind != EXPR_INT && d->value->kind != EXPR_STRING && d->value->kind != EXPR_CHAR){
			// print error
		}
	}
	if(d->code){
		stmt_typecheck(d->code);
	}
	decl_typecheck(d->next);
}
