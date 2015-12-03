%union {
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	char *name;
	struct param_list *param_list;
};
%start program
%type <decl> program decl_list decl
%type <stmt> stmt stmt_list stmt_matched n_stmt_matched stmt_block
%type <expr> expr expr_list n_expr_list opt_expr expr_and expr_comp expr_arith expr_geom expr_exp expr_unary expr_incr expr_grouping expr_primary expr_not_assgn n_expr_list_block expr_block
%type <type> type
%type <name> ident
%type <param_list> param_list n_param_list param 
%token TOKEN_IDENT
%token TOKEN_STRING
%token TOKEN_STRING_LITERAL
%token TOKEN_INT
%token TOKEN_INT_LITERAL
%token TOKEN_IF
%token TOKEN_ARRAY
%token TOKEN_BOOLEAN
%token TOKEN_CHAR
%token TOKEN_CHAR_LITERAL
%token TOKEN_ELSE
%token TOKEN_FALSE
%token TOKEN_FOR
%token TOKEN_FUNCTION
%token TOKEN_PRINT
%token TOKEN_RETURN
%token TOKEN_TRUE
%token TOKEN_VOID
%token TOKEN_WHILE
%token TOKEN_ADD
%token TOKEN_SUB
%token TOKEN_MULT
%token TOKEN_DIV
%token TOKEN_MOD
%token TOKEN_EXP
%token TOKEN_INCREMENT
%token TOKEN_DECREMENT
%token TOKEN_NEGATION
%token TOKEN_GT
%token TOKEN_GE
%token TOKEN_EQ
%token TOKEN_LE
%token TOKEN_LT
%token TOKEN_AND
%token TOKEN_OR
%token TOKEN_NE
%token TOKEN_ASSGN
%token TOKEN_SEMICOLON
%token TOKEN_COLON
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_LBRACE
%token TOKEN_RBRACE
%token TOKEN_LCURLBRACE
%token TOKEN_RCURLBRACE
%token TOKEN_COMMA
%token TOKEN_NOT
%token NOT_TOKEN
%{
struct decl * parser_result = 0;

// #include <math.h>
// #include <stdio.h>
#include <string.h>
#include "type.h"
#include "param_list.h"
#include "decl.h"
#include "stmt.h"
#include "expr.h"
#include "hash_table.h"
#include "symbol.h"


// #define YYSTYPE double

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

%}

%%
/* grammar goes here */
program		:	decl_list
				{parser_result = $1;}
	;
decl_list	:	decl decl_list 
				{$$ = $1; $1->next = $2;}
			|	/*nothing*/
				{$$ = 0;}
	;
decl 		:	ident TOKEN_COLON type TOKEN_ASSGN expr TOKEN_SEMICOLON
				{$$ = decl_create($1, $3, $5, 0, 0);}
			|	ident TOKEN_COLON type TOKEN_SEMICOLON
				{/*printf("creating decl\n");*/ $$ = decl_create($1, $3, 0, 0, 0);}
			|	ident TOKEN_COLON type TOKEN_ASSGN TOKEN_LCURLBRACE stmt_list TOKEN_RCURLBRACE  
				{$$ = decl_create($1, $3, 0, $6, 0); if(!$6) {$$->code = stmt_create(STMT_EMPTY, 0, 0, 0, 0, 0, 0);} /*printf("function\n");*/}
			|	ident TOKEN_COLON type TOKEN_ASSGN TOKEN_LCURLBRACE n_expr_list_block TOKEN_RCURLBRACE TOKEN_SEMICOLON // array[] int = expr_primary
				{$$ = decl_create($1, $3, $6, 0, 0);}
	;
type		:	TOKEN_STRING
				{$$ = type_create(TYPE_STRING, 0, 0, 0);}  // kind, params, subtype, opt_expr
			|	TOKEN_INT
				{$$ = type_create(TYPE_INTEGER, 0, 0, 0);}
			|	TOKEN_CHAR
				{$$ = type_create(TYPE_CHARACTER, 0, 0, 0);}
			|	TOKEN_BOOLEAN
				{$$ = type_create(TYPE_BOOLEAN, 0, 0, 0);}
			|	TOKEN_ARRAY TOKEN_LBRACE opt_expr TOKEN_RBRACE type  // HOW DO WE KEEP TRACK OF OPT_EXPR
				{$$ = type_create(TYPE_ARRAY, 0, $5, $3);}
			|	TOKEN_FUNCTION type TOKEN_LPAREN param_list TOKEN_RPAREN
				{$$ = type_create(TYPE_FUNCTION, $4, $2, 0);}
			|	TOKEN_VOID
				{$$ = type_create(TYPE_VOID, 0, 0, 0);}
	;
param_list 	:	n_param_list
				{$$ = $1;}
			|	/*nothing*/
				{$$ = 0;}
	;
n_param_list:	param 
				{$$ = $1;}
			|	param TOKEN_COMMA n_param_list
				{$$ = $1; $1->next = $3;}
	;
param 		:	ident TOKEN_COLON type
				{$$ = param_list_create($1, $3, 0);}  // name, type, next
	;
ident 		:	TOKEN_IDENT
				{char * temp; temp = strdup(yytext); $$ = temp;}
	;
stmt_list 	:	stmt stmt_list  // right recursion?
				{$$ = $1; $1->next = $2;}
			|	/*nothing*/
				{$$ = 0;}
	;
stmt 		:	stmt_matched
				{$$ = $1;}
			|	n_stmt_matched
				{$$ = $1;}
	;
stmt_matched:	decl
				{$$ = stmt_create(STMT_DECL, $1, 0, 0, 0, 0, 0);}  // kind, decl, init_expr, expr, next_expr, body, else_body
			|	expr TOKEN_SEMICOLON  // e.g. a = b;
				{$$ = stmt_create(STMT_EXPR, 0, 0, $1, 0, 0, 0);}
			|	TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt_matched  // for(;;)  
				{$$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0);}
			|	TOKEN_RETURN opt_expr TOKEN_SEMICOLON
				{$$ = stmt_create(STMT_RETURN, 0, 0, $2, 0, 0, 0);}
			| 	TOKEN_PRINT expr_list TOKEN_SEMICOLON
				{$$ = stmt_create(STMT_PRINT, 0, 0, $2, 0, 0, 0);}
			|	TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt_matched TOKEN_ELSE stmt_matched
				{$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7);}
			|	stmt_block
				{$$ = $1;}
	;
stmt_block 	:	TOKEN_LCURLBRACE stmt_list TOKEN_RCURLBRACE  // {...}
				{$$ = stmt_create(STMT_BLOCK, 0, 0, 0, 0, $2, 0);}
	;
n_stmt_matched:	TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt // if_unmatched
				{$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, 0); /*printf("gotem\n");*/}
			|	TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt_matched TOKEN_ELSE n_stmt_matched
				{$$ = stmt_create(STMT_IF_ELSE, 0, 0, $3, 0, $5, $7); /*printf("gotem\n");*/}
			|	TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN n_stmt_matched  // for_unmatched
				{$$ = stmt_create(STMT_FOR, 0, $3, $5, $7, $9, 0);}
	;
opt_expr 	: 	expr
				{$$ = $1;}
			|	/*nothing*/
				{$$ = 0;}
	;
expr_list 	: 	n_expr_list
				{$$ = $1;}
			|	/*nothing*/
				{$$ = 0;}
	;
n_expr_list	:	expr TOKEN_COMMA n_expr_list
				{$$ = expr_create(EXPR_LIST, $1, $3);}
			|	expr
				{$$ = $1;}
	;
expr_block	:	TOKEN_LCURLBRACE n_expr_list_block TOKEN_RCURLBRACE
				{$$ = expr_create(EXPR_BLOCK, $2, 0);}
	;
n_expr_list_block : expr_block TOKEN_COMMA n_expr_list_block 
					{$$ = expr_create(EXPR_BLOCK, $1, $3);}
			|	expr_block
				{$$ = $1;}
			|	n_expr_list
				{$$ = expr_create(EXPR_BLOCK, $1, 0);}
	;
expr		:	expr TOKEN_ASSGN expr_not_assgn
				{$$ = expr_create(EXPR_ASSGN, $1, $3);}
			|	expr_not_assgn 
				{$$ = $1;}
	;
expr_not_assgn :expr_not_assgn TOKEN_OR expr_and
				{$$ = expr_create(EXPR_OR, $1, $3);}
			|	expr_and
				{$$ = $1;}
	;
expr_and 	:	expr_and TOKEN_AND expr_comp
				{$$ = expr_create(EXPR_AND, $1, $3);}
			|	expr_comp
				{$$ = $1;}
	;
expr_comp 	:	expr_comp TOKEN_LE expr_arith
				{$$ = expr_create(EXPR_LE, $1, $3);}
			|	expr_comp TOKEN_GE expr_arith
				{$$ = expr_create(EXPR_GE, $1, $3);}
			|	expr_comp TOKEN_LT expr_arith
				{$$ = expr_create(EXPR_LT, $1, $3);}
			|	expr_comp TOKEN_GT expr_arith
				{$$ = expr_create(EXPR_GT, $1, $3);}
			|	expr_comp TOKEN_EQ expr_arith
				{$$ = expr_create(EXPR_EQ, $1, $3);}
			|	expr_comp TOKEN_NE expr_arith
				{$$ = expr_create(EXPR_NE, $1, $3);}
			|	expr_arith
				{$$ = $1;}
	;
expr_arith 	:	expr_arith TOKEN_ADD expr_geom
				{$$ = expr_create(EXPR_ADD, $1, $3);}
			|	expr_arith TOKEN_SUB expr_geom
				{$$ = expr_create(EXPR_SUB, $1, $3);}
			|	expr_geom
				{$$ = $1;}
	;
expr_geom 	:	expr_geom TOKEN_MULT expr_exp
				{$$ = expr_create(EXPR_MULT, $1, $3);}
			| 	expr_geom TOKEN_DIV expr_exp
				{$$ = expr_create(EXPR_DIV, $1, $3);}
			|	expr_geom TOKEN_MOD expr_exp
				{$$ = expr_create(EXPR_MOD, $1, $3);}
			|	expr_exp
				{$$ = $1;}
	;
expr_exp	:	expr_exp TOKEN_EXP expr_unary
				{$$ = expr_create(EXPR_EXP, $1, $3);}
			| 	expr_unary
				{$$ = $1;}
	;
expr_unary 	:	TOKEN_NOT expr_unary
				{$$ = expr_create(EXPR_NOT, 0, $2);}
			|	TOKEN_NEGATION expr_unary
				{$$ = expr_create(EXPR_NEG, 0, $2);}
			|	expr_incr
				{$$ = $1;}
	;
expr_incr 	:	expr_grouping TOKEN_INCREMENT
				{$$ = expr_create(EXPR_INCR, $1, 0);}
			|	expr_grouping TOKEN_DECREMENT
				{$$ = expr_create(EXPR_DECR, $1, 0);}
			|	expr_grouping
				{$$ = $1;}
	;
expr_grouping :	TOKEN_LPAREN expr TOKEN_RPAREN
				{$$ = $2;}
			|	ident TOKEN_LBRACE expr TOKEN_RBRACE expr_array  // primary?
				{$$ = expr_create(EXPR_BRACKET, expr_create_name($1), $3);}
			|	ident TOKEN_LPAREN expr_list TOKEN_RPAREN 
				{$$ = expr_create(EXPR_FUNC, expr_create_name($1), $3);}
			|	expr_primary
				{$$ = $1;}
	;
expr_array  :	TOKEN_LBRACE expr TOKEN_RBRACE expr_array
			|	/* nothing */
			;
expr_primary:	TOKEN_INT_LITERAL
				{int temp = atoi(yytext); $$ = expr_create_integer_literal(temp);/*printf("%d\n", $$->literal_value);*/}
			|	ident
				{$$ = expr_create_name($1);}
			|	TOKEN_CHAR_LITERAL
				{$$ = expr_create_character_literal((yytext[0])); }
			|	TOKEN_TRUE
				{$$ = expr_create_boolean_literal(1);}
			|	TOKEN_FALSE
				{$$ = expr_create_boolean_literal(0);}
			|	TOKEN_STRING_LITERAL
				{char * temp; temp = strdup(yytext); $$ = expr_create_string_literal(temp);}
	;


%%

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 1;
}
