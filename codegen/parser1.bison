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

%{

#include <math.h>
#include <stdio.h>

#define YYSTYPE double

extern char *yytext();
extern int yylex();
extern int yyerror( char *str );

%}

%%
/* grammar goes here */
program		:	decl_list
	;
decl_list	:	decl decl_list 
			|	/*nothing*/
	;
decl 		:	ident TOKEN_COLON type TOKEN_ASSGN expr
			|	ident TOKEN_COLON type TOKEN_SEMICOLON
			|	ident TOKEN_COLON type TOKEN_ASSGN TOKEN_LCURLBRACE stmt_list TOKEN_RCURLBRACE
	;
type		:	TOKEN_STRING
			|	TOKEN_INT
			|	TOKEN_CHAR
			|	TOKEN_BOOLEAN
			|	TOKEN_ARRAY TOKEN_LBRACE expr TOKEN_RBRACE
			|	TOKEN_FUNCTION type TOKEN_LPAREN param_list TOKEN_RPAREN
			|	TOKEN_VOID
	;
param_list 	:	n_param_list
			|	/*nothing*/
	;
n_param_list:	param 
			|	param TOKEN_COMMA n_param_list
	;
param 		:	ident TOKEN_COLON type
	;
ident 		:	TOKEN_IDENT
	;
stmt_list 	:	stmt stmt_list  // right recursion?
			|
	;
stmt 		:	stmt_matched
			|	n_stmt_matched
	;
stmt_matched:	decl
			|	expr TOKEN_SEMICOLON  // e.g. a = b;
			|	ident TOKEN_ASSGN expr TOKEN_SEMICOLON  // h = f(c);
			|	TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt_matched  // for(;;)
			|	TOKEN_LCURLBRACE stmt_list TOKEN_RCURLBRACE  // {...}
			|	TOKEN_RETURN expr TOKEN_SEMICOLON
			| 	TOKEN_PRINT expr_list TOKEN_SEMICOLON
			|	TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt_matched TOKEN_ELSE stmt_matched
	;
n_stmt_matched:	TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt // if_unmatched
			|	TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt_matched TOKEN_ELSE n_stmt_matched
			|	TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN n_stmt_matched  // for_unmatched
	;
opt_expr 	: expr
			|
	;
expr_list 	: 	n_expr_list
			|	/*nothing*/
	;
n_expr_list	:	expr TOKEN_COMMA n_expr_list
			|	expr
	;

expr		:	expr TOKEN_OR expr_eq
			|	expr TOKEN_AND expr_eq
			|	expr_eq 
	;
expr_eq 	:	expr_eq TOKEN_EQ expr_comp
			|	expr_eq TOKEN_NE expr_comp
			|	expr_comp
	;
expr_comp 	:	expr_comp TOKEN_LE expr_arith
			|	expr_comp TOKEN_GE expr_arith
			|	expr_comp TOKEN_LT expr_arith
			|	expr_comp TOKEN_GT expr_arith
			|	expr_arith
	;
expr_arith 	:	expr_arith TOKEN_ADD expr_geom
			|	expr_arith TOKEN_SUB expr_geom
			|	expr_geom
	;
expr_geom 	:	expr_geom TOKEN_MULT expr_unary_arith
			| 	expr_geom TOKEN_DIV expr_unary_arith
			|	expr_geom TOKEN_MOD expr_unary_arith
			|	expr_unary_arith
	;
expr_unary_arith :	TOKEN_ADD expr_neg
			|	TOKEN_SUB expr_neg
			| 	expr_neg
	;
expr_neg 	:	TOKEN_NOT expr_incr
			|	expr_incr
	;
expr_incr 	:	primary_expr TOKEN_INCREMENT
			|	primary_expr TOKEN_DECREMENT
			|	primary_expr
	;
primary_expr:	TOKEN_INT_LITERAL
			|	ident
			|	TOKEN_CHAR_LITERAL
			|	TOKEN_TRUE
			|	TOKEN_FALSE
			|	TOKEN_STRING_LITERAL
			|	TOKEN_LPAREN expr TOKEN_RPAREN
			|	TOKEN_LCURLBRACE expr_list TOKEN_RCURLBRACE
			// |	ident TOKEN_LPAREN expr_list TOKEN_RPAREN  // function call f(...)
	;


%%

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
}