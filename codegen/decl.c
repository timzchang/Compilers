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
	// printf("%d", d->type->kind);
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
	}else if(d->code){
		printf(" = ");
		printf("{");  // STMT_PRINT PRINTS \N FIRST ALWAYS
		stmt_print(d->code, indent+4);
		printf("\n%*s",indent,"");
		printf("}\n");
	}else{
		printf(";\n");
	}
	// printf("\n");
	decl_print(d->next, indent);
}

void decl_resolve(struct decl *d){
	if(!d) return;

	// so hear we need to do something to add something to the symbol table

	struct symbol *sym;
	sym = scope_lookup_single(d->name);
	if(sym){  // var is already in scope
		if(sym->type->kind != TYPE_FUNCTION || sym->code == 1){  // either a var or a fully declared func
			printf("resolve error: %s already defined in this scope\n", d->name);
			error_count++;
		}else{
			if(d->code){  // if func decl has code
				if(!type_compare(d->type, sym->type)){  // if return type different
					printf("resolve error: %s is redefined with subtype ", d->name);
					type_print(d->type);
					printf(" expecting ");
					type_print(sym->type);
					printf("\n");
					error_count++;
				}else{  // defining a prototype
					d->symbol = sym;
					printf("%s resolves to global %s\n", d->name, sym->name);
					sym->code = 1;
					scope_enter();
					param_list_resolve(d->type->params);
					stmt_resolve(d->code);
					scope_leave();
				}
			}else{
				printf("resolve error: %s already defined in this scope\n", d->name);
				error_count++;
			}
		}
	}else{  // var is not in scope
		symbol_t kind;
		if(scope_level() == 1){
			kind = SYMBOL_GLOBAL;
			sym = symbol_create(kind, d->type, d->name);
			scope_bind(d->name, sym);
			printf("%s resolves to global %s\n", d->name, sym->name);
		}else{
			int *which = hash_table_lookup(h, "0locals");  // which grabs the number of locals from the hash table
			sym = symbol_create(SYMBOL_LOCAL, d->type, d->name);
			sym->which = *which;
			*which += 1;
			scope_bind(d->name, sym);
			d->symbol = sym;
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
			sym->code = 1;
		}
		
	}
	decl_resolve(d->next);
}

void decl_typecheck(struct decl *d){
	if(!d) return;
	struct type *t = expr_typecheck(d->value);
	if(d->type->kind != TYPE_FUNCTION && d->value && !type_compare(d->type, t)){  // check assignment
		// error_print(d->type, t);  // this will print the relevant typechecking error
		printf("type error: cannot assign ");
		type_print(d->type);
		printf(" (");
		printf("%s",d->name);
		printf(")");
		printf(" to ");
		type_print(t);
		printf(" ");
		expr_print(d->value);
		printf("\n");
		error_count++;
	}
	if(d->value){  // check
		if(d->symbol->kind == SYMBOL_GLOBAL && !expr_is_constant(d->value)){
			// print error
			printf("type error: global ");
			printf("%s", d->name);
			printf(" cannot be assigned to non-constant\n");
			error_count++;
		}
	}
	if(d->code){
		stmt_typecheck(d->code, d);
	}
	decl_typecheck(d->next);
}

void decl_codegen(struct decl *d, char * output){

}