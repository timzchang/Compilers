#include <stdio.h>
#include "token.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// #include "parser.tab.h"
#include "type.h"
#include "decl.h"
#include "expr.h"
#include "stmt.h"
#include "param_list.h"
#include "hash_table.h"
#include "scope.h"

extern int yyparse();
extern int yylex();

// the global hash_table.
struct hash_table *h;
int error_count;
int reg[16] = {1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0};  // free registers
int label_count = 0;
int str_count = 0;
int ret_count = 0;
int arg_count = 0;

/*	Precondition: an unedited char ptr
	Postcondition: string is modified to get rid of null char and white space.
*/

int scan(char *file){
	extern FILE * yyin;
	extern char * yytext;
	yyin = fopen(file, "r");
	int t, i;
	while(1){
		t = yylex();  // yylex returns token_t, hich are ints corresponding to the enum in token.
		if(yytext[0]=='\0') exit(0);
		if(t==NOT_TOKEN){
			fprintf(stderr,"scan error: %s is not a valid character\n",yytext);
			exit(1);
		}else if(!t){
			break;  // if t==0, which is the first token defined, break the while loop...
		}else{
			if(t==TOKEN_STRING_LITERAL || t==TOKEN_CHAR_LITERAL){
				edit_string(yytext);
				if(strlen(yytext)>255){
					fprintf(stderr,"scan error: token is too long\n");
				 	exit(1);
				}
				printf("%s %s\n", token_string(t), yytext);
			}else{
				if(t==TOKEN_IDENT){
					if(strlen(yytext)>255){
						fprintf(stderr,"scan error: token is too long\n");
						exit(1);
					}
				}
				printf("%s\n", token_string(t));
			}
		}

	}
	return 0;
}

int parse(char *file) {
	extern FILE * yyin;
	extern char * yytext;
	extern struct decl *parser_result;
	//extern struct decl *parser_result;
	// extern int yyparse();
	yyin = fopen(file, "r");
	if(!yyin){
		fprintf(stderr, "error, can't read file\n");
		exit(1);
	}else if(yyparse()==0){
		printf("parsed!\n");
		decl_print(parser_result, 0);
		printf("\n");
		return 0;
	}else{
		fprintf(stderr, "error, can't be parsed\n");
		exit(1);
	}
}

int resolve(char *file){
	extern FILE * yyin;
	extern char * yytext;
	extern struct decl *parser_result;
	h = hash_table_create(0,0);
	yyin = fopen(file, "r");
	if(!yyin){
		fprintf(stderr, "error, can't read file\n");
		exit(1);
	}else if(yyparse()==0){
		printf("parsed!\n");
		decl_resolve(parser_result);
		printf("Error count: %d\n", error_count);
		return 0;
	}else{
		fprintf(stderr, "error, can't be parsed\n");
		exit(1);
	}
}

int typecheck(char *file){
	extern FILE * yyin;
	extern char * yytext;
	extern struct decl *parser_result;
	h = hash_table_create(0,0);
	yyin = fopen(file, "r");
	if(!yyin){
		fprintf(stderr, "error, can't read file\n");
		exit(1);
	}else if(yyparse()==0){
		//printf("parsed!\n");
		decl_resolve(parser_result);
		printf("Resolve error count: %d\n", error_count);
		if(error_count >0){
			exit(1);
		}
		decl_typecheck(parser_result);
		if(error_count>0){
			exit(1);
		}
		printf("Typecheck error count: %d\n", error_count);
		return 0;
	}else{
		fprintf(stderr, "error, can't be parsed\n");
		exit(1);
	}
}

int codegen(char *file, char *output_file){
	extern FILE * yyin;
	extern char * yytext;
	extern struct decl *parser_result;
	h = hash_table_create(0,0);
	yyin = fopen(file, "r");
	FILE * output = fopen(output_file, "w");
	if(!yyin){
		fprintf(stderr, "error, can't read file\n");
		exit(1);
	}else if(yyparse()==0){
		//printf("parsed!\n");
		decl_resolve(parser_result);
		//printf("Resolve error count: %d\n", error_count);
		if(error_count >0){
			exit(1);
		}
		decl_typecheck(parser_result);
		//printf("Typecheck error count: %d\n", error_count);
		if(error_count>0){
			exit(1);
		}
		decl_codegen(parser_result, output);
		//printf("r[0] %d\nr[1] %d\nr[2] %d\nr[3] %d\nr[4] %d\nr[5] %d\nr[6] %d\nr[7] %d\nr[8] %d\nr[9] %d\nr[10] %d\nr[11] %d\nr[12] %d\nr[13] %d\nr[14] %d\nr[15] %d\n",
		//	reg[0], reg[1], reg[2], reg[3], reg[4], reg[5], reg[6], reg[7], reg[8], reg[9], reg[10], reg[11], reg[12], reg[13], reg[14], reg[15]);
		return 0;
	}else{
		fprintf(stderr, "error, can't be parsed\n");
		exit(1);
	}
}

int main(int argc, char * argv[]){
	extern FILE * yyin;
	extern char * yytext;
	extern struct decl *parser_result;
	if(argc > 2 && strcmp(argv[1],"-scan")==0){
		// yyin = fopen(argv[2], "r");
		scan(argv[2]);
	}else if(argc >2 && strcmp(argv[1], "-parse")==0){
		parse(argv[2]);
	}else if(argc >2 && strcmp(argv[1], "-resolve")==0){
		resolve(argv[2]);
	}else if(argc >2 && strcmp(argv[1], "-typecheck")==0){
		typecheck(argv[2]);
	}else if(argc >2 && strcmp(argv[1], "-codegen")==0){
		if(argc == 4){
			codegen(argv[2], argv[3]);
		}else{
			printf("must provide output file\n");
		}
	}else{
		printf("cannot open\n");
		exit(1);
	}
	/*int t, i;
	while(1){
		t = yylex();  // yylex returns token_t, hich are ints corresponding to the enum in token.
		if(yytext[0]=='\0') exit(0);
		if(t==NOT_TOKEN){
			fprintf(stderr,"scan error: %s is not a valid character\n",yytext);
			exit(1);
		}else if(!t){
			break;  // if t==0, which is the first token defined, break the while loop...
		}else{
			if(t==TOKEN_STRING_LITERAL || t==TOKEN_CHAR_LITERAL){
				edit_string(yytext);
				if(strlen(yytext)>255){
					fprintf(stderr,"scan error: token is too long\n");
				 	exit(1);
				}
				printf("%s %s\n", token_string(t), yytext);
			}else{
				if(t==TOKEN_IDENT){
					if(strlen(yytext)>255){
						fprintf(stderr,"scan error: token is too long\n");
						exit(1);
					}
				}
				printf("%s\n", token_string(t));
			}
		}

	}*/
}

