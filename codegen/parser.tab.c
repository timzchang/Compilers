#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 1 "parser.bison"
typedef union {
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	char *name;
	struct param_list *param_list;
} YYSTYPE;
#line 65 "parser.bison"
struct decl * parser_result = 0;

/* #include <math.h>*/
/* #include <stdio.h>*/
#include <string.h>
#include "type.h"
#include "param_list.h"
#include "decl.h"
#include "stmt.h"
#include "expr.h"
#include "hash_table.h"
#include "symbol.h"


/* #define YYSTYPE double*/

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

#line 53 "parser.tab.c"
#define TOKEN_IDENT 257
#define TOKEN_STRING 258
#define TOKEN_STRING_LITERAL 259
#define TOKEN_INT 260
#define TOKEN_INT_LITERAL 261
#define TOKEN_IF 262
#define TOKEN_ARRAY 263
#define TOKEN_BOOLEAN 264
#define TOKEN_CHAR 265
#define TOKEN_CHAR_LITERAL 266
#define TOKEN_ELSE 267
#define TOKEN_FALSE 268
#define TOKEN_FOR 269
#define TOKEN_FUNCTION 270
#define TOKEN_PRINT 271
#define TOKEN_RETURN 272
#define TOKEN_TRUE 273
#define TOKEN_VOID 274
#define TOKEN_WHILE 275
#define TOKEN_ADD 276
#define TOKEN_SUB 277
#define TOKEN_MULT 278
#define TOKEN_DIV 279
#define TOKEN_MOD 280
#define TOKEN_EXP 281
#define TOKEN_INCREMENT 282
#define TOKEN_DECREMENT 283
#define TOKEN_NEGATION 284
#define TOKEN_GT 285
#define TOKEN_GE 286
#define TOKEN_EQ 287
#define TOKEN_LE 288
#define TOKEN_LT 289
#define TOKEN_AND 290
#define TOKEN_OR 291
#define TOKEN_NE 292
#define TOKEN_ASSGN 293
#define TOKEN_SEMICOLON 294
#define TOKEN_COLON 295
#define TOKEN_LPAREN 296
#define TOKEN_RPAREN 297
#define TOKEN_LBRACE 298
#define TOKEN_RBRACE 299
#define TOKEN_LCURLBRACE 300
#define TOKEN_RCURLBRACE 301
#define TOKEN_COMMA 302
#define TOKEN_NOT 303
#define NOT_TOKEN 304
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,    2,    2,   24,   24,   24,
   24,   24,   24,   24,   26,   26,   27,   27,   28,   25,
    4,    4,    3,    3,    5,    5,    5,    5,    5,    5,
    5,    7,    6,    6,    6,   11,   11,    9,    9,   10,
   10,   23,   22,   22,   22,    8,    8,   21,   21,   12,
   12,   13,   13,   13,   13,   13,   13,   13,   14,   14,
   14,   15,   15,   15,   15,   16,   16,   17,   17,   17,
   18,   18,   18,   19,   19,   19,   19,   29,   29,   20,
   20,   20,   20,   20,   20,
};
short yylen[] = {                                         2,
    1,    2,    0,    6,    4,    7,    8,    1,    1,    1,
    1,    5,    5,    1,    1,    0,    1,    3,    3,    1,
    2,    0,    1,    1,    1,    2,    9,    3,    3,    7,
    1,    3,    5,    7,    9,    1,    0,    1,    0,    3,
    1,    3,    3,    1,    1,    3,    1,    3,    1,    3,
    1,    3,    3,    3,    3,    3,    3,    1,    3,    3,
    1,    3,    3,    3,    1,    3,    1,    2,    2,    1,
    2,    2,    1,    3,    5,    4,    1,    4,    0,    1,
    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
   20,    0,    1,    0,    0,    2,    0,    8,    9,    0,
   11,   10,    0,   14,    0,    0,    0,    0,    5,   85,
   80,   82,   84,   83,    0,    0,    0,   36,    0,    0,
    0,    0,    0,    0,   67,   70,    0,   77,    0,    0,
    0,    0,    0,   69,    0,   68,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   71,   72,    0,    0,    0,    0,    0,    0,   15,    0,
    0,    0,    0,    0,    0,   25,    0,    0,   23,   24,
   31,    0,   45,    0,    0,    0,    4,   74,   12,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,    0,   46,    0,    0,   38,    0,    0,   13,
    0,    0,    0,    0,    0,    0,    0,    0,   21,    0,
    6,   26,    0,    0,    0,   76,    0,   19,   18,    0,
    0,   29,   28,   32,   42,   40,    7,    0,   43,    0,
   75,    0,    0,    0,   33,    0,    0,    0,    0,    0,
   78,   30,   34,    0,    0,   27,   35,
};
short yydgoto[] = {                                       2,
    3,   76,   77,  116,   79,   80,   81,   28,  106,   83,
   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,
   39,  117,   85,   15,   40,   68,   69,   70,  141,
};
short yysindex[] = {                                   -247,
    0,    0,    0, -247, -277,    0, -193,    0,    0, -219,
    0,    0, -193,    0, -255,  -60, -266, -164,    0,    0,
    0,    0,    0,    0,  -60,  -60,  -60,    0, -241, -199,
  -67, -208, -227, -197,    0,    0, -209,    0, -268, -232,
 -247, -108, -198,    0, -196,    0, -193,  -60,  -60,  -60,
  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,  -60,
    0,    0,  -60,  -60,  -60,  -60, -192, -191,    0, -203,
 -188, -180,  -60,  -60, -108,    0,  -91, -171,    0,    0,
    0, -287,    0, -168, -167, -206,    0,    0,    0,  -67,
 -208, -208, -208, -208, -208, -208, -227, -227, -197, -197,
 -197,    0, -199,    0, -162, -163,    0, -161, -193,    0,
 -247,  -60,  -60, -153, -152, -157, -156,  -91,    0, -148,
    0,    0,  -60, -147,  -70,    0, -150,    0,    0, -145,
 -139,    0,    0,    0,    0,    0,    0,  -70,    0,  -60,
    0,  -91,  -60, -142,    0, -105, -135, -150,  -91,  -60,
    0,    0,    0, -130,  -91,    0,    0,
};
short yyrindex[] = {                                    172,
    0,    0,    0,  172,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -126,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  344,
 -176,  224,  168,   68,    0,    0,   22,    0, -214,  -32,
 -123, -125,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -118,    0,    0,    0,    0, -113,
    0,    0, -111, -109, -125,    0, -125,    0,    0,    0,
    0, -107,    0,    0, -101,   49,    0,    0,    0,  -62,
  242,  260,  278,  296,  314,  332,  187,  206,   95,  122,
  149,    0,  356,    0, -281,    0,    0,    0,    0,    0,
    0,    0, -109,    0,    0,    0,    0, -125,    0,    0,
    0,    0,    0,    0,    0,    0,   -5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -109,    0,    0, -240,    0,   -5,    0, -104,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  186,   50,   60,  -28, -115, -114,    0,  -18,  131,  -61,
  -68,  147,  163,  610,   55,   70,  -16,    0,    0,    0,
    0,  -39,    0,  -11,    1,    0,  103,    0,   67,
};
#define YYTABLESIZE 664
short yytable[] = {                                      43,
    5,   17,   84,  107,    5,  115,  122,   45,   44,    1,
   46,  107,   41,   78,  123,   41,   23,    7,   23,   41,
   23,   23,   63,   82,   64,   23,  146,   23,   23,   41,
   23,   23,   23,  152,  153,   89,   23,   18,   19,  156,
  157,   67,   86,  102,  131,  104,  105,  108,  119,    4,
   57,   58,   59,    4,  105,   23,   82,   47,  120,   23,
   23,  136,   23,   65,    8,   66,    9,   55,   56,   10,
   11,   12,   61,   62,  147,   86,   13,   86,   16,   47,
   14,  154,   47,   60,   47,  139,   47,   47,    7,   65,
   48,   66,    1,  130,   20,   87,   21,  128,  111,  120,
   88,   22,  109,   23,  105,  110,  105,  112,   24,   97,
   98,   67,   25,   51,   51,  113,   51,   51,   86,  105,
   51,  144,   51,  120,   51,   51,   99,  100,  101,  121,
  120,   26,  124,  126,  125,   42,  120,  127,   27,  123,
  132,  133,   86,  134,  135,  122,  137,  140,    1,   86,
   20,  142,   21,   71,  143,   86,  148,   22,  150,   23,
   72,  149,   73,   74,   24,    1,  155,   20,   25,   21,
   71,    3,   37,   16,   22,   22,   23,   72,   39,   73,
   74,   24,   39,   17,   37,   25,    1,   26,   20,    6,
   21,   75,   37,   41,   27,   22,    1,   23,   20,   44,
   21,  145,   24,  114,   26,   22,   25,   23,  118,  103,
   90,   27,   24,  129,  151,    0,   25,   49,   50,   51,
   52,   53,    0,    0,   54,   26,    0,   50,   50,  138,
   50,   50,   27,    0,   50,   26,   50,    0,   50,   50,
    0,    0,   27,   81,   81,   81,   81,   81,   81,   81,
   81,    0,   81,   81,   81,   81,   81,   81,   81,   81,
   81,   81,    0,    0,   81,    0,   81,    0,   81,   81,
   79,   79,   79,   79,   79,   79,   79,   79,    0,   79,
   79,   79,   79,   79,   79,   79,   79,   79,   79,    0,
    0,   79,    0,   79,    0,   79,   79,   73,   73,   73,
   73,   73,   73,    0,    0,    0,   73,   73,   73,   73,
   73,   73,   73,   73,   73,   73,    0,    0,   73,    0,
   73,    0,   73,   73,   81,   81,   81,   81,   81,   81,
   81,   81,    0,   81,   81,   81,   81,   81,   81,   81,
   81,   81,   81,   65,   65,   65,   65,   65,    0,   81,
   81,    0,   65,   65,   65,   65,   65,   65,   65,   65,
   65,   65,    0,    0,   65,    0,   65,    0,   65,   65,
   62,   62,   62,   62,   62,    0,    0,    0,    0,   62,
   62,   62,   62,   62,   62,   62,   62,   62,   62,    0,
    0,   62,    0,   62,    0,   62,   62,   63,   63,   63,
   63,   63,    0,    0,    0,    0,   63,   63,   63,   63,
   63,   63,   63,   63,   63,   63,    0,    0,   63,    0,
   63,    0,   63,   63,   64,   64,   64,   64,   64,    0,
    0,    0,    0,   64,   64,   64,   64,   64,   64,   64,
   64,   64,   64,   61,   61,   64,    0,   64,    0,   64,
   64,    0,   61,   61,   61,   61,   61,   61,   61,   61,
   61,   61,   59,   59,   61,    0,   61,    0,   61,   61,
    0,   59,   59,   59,   59,   59,   59,   59,   59,   59,
   59,   60,   60,   59,    0,   59,    0,   59,   59,    0,
   60,   60,   60,   60,   60,   60,   60,   60,   60,   60,
    0,    0,   60,    0,   60,    0,   60,   60,   58,   58,
   58,   58,   58,   58,   58,   58,   58,   58,    0,    0,
   58,    0,   58,    0,   58,   58,   55,   55,   55,   55,
   55,   55,   55,   55,   55,   55,    0,    0,   55,    0,
   55,    0,   55,   55,   53,   53,   53,   53,   53,   53,
   53,   53,   53,   53,    0,    0,   53,    0,   53,    0,
   53,   53,   56,   56,   56,   56,   56,   56,   56,   56,
   56,   56,    0,    0,   56,    0,   56,    0,   56,   56,
   52,   52,   52,   52,   52,   52,   52,   52,   52,   52,
    0,    0,   52,    0,   52,    0,   52,   52,   54,   54,
   54,   54,   54,   54,   54,   54,   54,   54,    0,    0,
   54,    0,   54,    0,   54,   54,   57,   57,   57,   57,
   57,   57,   57,   57,   57,   57,    0,    0,   57,    0,
   57,    0,   57,   57,   49,    0,   49,   49,    0,    0,
   49,    0,   49,    0,   49,   49,   48,    0,   48,   48,
    0,    0,   48,    0,   48,    0,   48,   48,   91,   92,
   93,   94,   95,   96,
};
short yycheck[] = {                                      18,
    0,   13,   42,   65,    4,   74,  294,   26,   25,  257,
   27,   73,  294,   42,  302,  297,  257,  295,  259,  301,
  261,  262,  291,   42,  293,  266,  142,  268,  269,  296,
  271,  272,  273,  149,  149,   47,  277,  293,  294,  155,
  155,   41,   42,   60,  113,   64,   65,   66,   77,    0,
  278,  279,  280,    4,   73,  296,   75,  299,   77,  300,
  301,  123,  303,  296,  258,  298,  260,  276,  277,  263,
  264,  265,  282,  283,  143,   75,  270,   77,  298,  294,
  274,  150,  297,  281,  299,  125,  301,  302,  295,  296,
  290,  298,  257,  112,  259,  294,  261,  109,  302,  118,
  297,  266,  295,  268,  123,  297,  125,  296,  273,   55,
   56,  111,  277,  290,  291,  296,  293,  294,  118,  138,
  297,  140,  299,  142,  301,  302,   57,   58,   59,  301,
  149,  296,  301,  297,  302,  300,  155,  299,  303,  302,
  294,  294,  142,  301,  301,  294,  294,  298,  257,  149,
  259,  297,  261,  262,  294,  155,  299,  266,  294,  268,
  269,  267,  271,  272,  273,  257,  297,  259,  277,  261,
  262,    0,  299,  297,  266,  301,  268,  269,  297,  271,
  272,  273,  294,  297,  294,  277,  257,  296,  259,    4,
  261,  300,  297,  301,  303,  266,  257,  268,  259,  301,
  261,  142,  273,   73,  296,  266,  277,  268,  300,   63,
   48,  303,  273,  111,  148,   -1,  277,  285,  286,  287,
  288,  289,   -1,   -1,  292,  296,   -1,  290,  291,  300,
  293,  294,  303,   -1,  297,  296,  299,   -1,  301,  302,
   -1,   -1,  303,  276,  277,  278,  279,  280,  281,  282,
  283,   -1,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,   -1,   -1,  297,   -1,  299,   -1,  301,  302,
  276,  277,  278,  279,  280,  281,  282,  283,   -1,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,   -1,
   -1,  297,   -1,  299,   -1,  301,  302,  276,  277,  278,
  279,  280,  281,   -1,   -1,   -1,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  294,   -1,   -1,  297,   -1,
  299,   -1,  301,  302,  276,  277,  278,  279,  280,  281,
  282,  283,   -1,  285,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  276,  277,  278,  279,  280,   -1,  301,
  302,   -1,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,   -1,   -1,  297,   -1,  299,   -1,  301,  302,
  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,   -1,
   -1,  297,   -1,  299,   -1,  301,  302,  276,  277,  278,
  279,  280,   -1,   -1,   -1,   -1,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  294,   -1,   -1,  297,   -1,
  299,   -1,  301,  302,  276,  277,  278,  279,  280,   -1,
   -1,   -1,   -1,  285,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  276,  277,  297,   -1,  299,   -1,  301,
  302,   -1,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  276,  277,  297,   -1,  299,   -1,  301,  302,
   -1,  285,  286,  287,  288,  289,  290,  291,  292,  293,
  294,  276,  277,  297,   -1,  299,   -1,  301,  302,   -1,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,
   -1,   -1,  297,   -1,  299,   -1,  301,  302,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,   -1,   -1,
  297,   -1,  299,   -1,  301,  302,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  294,   -1,   -1,  297,   -1,
  299,   -1,  301,  302,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  294,   -1,   -1,  297,   -1,  299,   -1,
  301,  302,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,   -1,   -1,  297,   -1,  299,   -1,  301,  302,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,
   -1,   -1,  297,   -1,  299,   -1,  301,  302,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  294,   -1,   -1,
  297,   -1,  299,   -1,  301,  302,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  294,   -1,   -1,  297,   -1,
  299,   -1,  301,  302,  291,   -1,  293,  294,   -1,   -1,
  297,   -1,  299,   -1,  301,  302,  291,   -1,  293,  294,
   -1,   -1,  297,   -1,  299,   -1,  301,  302,   49,   50,
   51,   52,   53,   54,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 304
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TOKEN_IDENT","TOKEN_STRING",
"TOKEN_STRING_LITERAL","TOKEN_INT","TOKEN_INT_LITERAL","TOKEN_IF","TOKEN_ARRAY",
"TOKEN_BOOLEAN","TOKEN_CHAR","TOKEN_CHAR_LITERAL","TOKEN_ELSE","TOKEN_FALSE",
"TOKEN_FOR","TOKEN_FUNCTION","TOKEN_PRINT","TOKEN_RETURN","TOKEN_TRUE",
"TOKEN_VOID","TOKEN_WHILE","TOKEN_ADD","TOKEN_SUB","TOKEN_MULT","TOKEN_DIV",
"TOKEN_MOD","TOKEN_EXP","TOKEN_INCREMENT","TOKEN_DECREMENT","TOKEN_NEGATION",
"TOKEN_GT","TOKEN_GE","TOKEN_EQ","TOKEN_LE","TOKEN_LT","TOKEN_AND","TOKEN_OR",
"TOKEN_NE","TOKEN_ASSGN","TOKEN_SEMICOLON","TOKEN_COLON","TOKEN_LPAREN",
"TOKEN_RPAREN","TOKEN_LBRACE","TOKEN_RBRACE","TOKEN_LCURLBRACE",
"TOKEN_RCURLBRACE","TOKEN_COMMA","TOKEN_NOT","NOT_TOKEN",
};
char *yyrule[] = {
"$accept : program",
"program : decl_list",
"decl_list : decl decl_list",
"decl_list :",
"decl : ident TOKEN_COLON type TOKEN_ASSGN expr TOKEN_SEMICOLON",
"decl : ident TOKEN_COLON type TOKEN_SEMICOLON",
"decl : ident TOKEN_COLON type TOKEN_ASSGN TOKEN_LCURLBRACE stmt_list TOKEN_RCURLBRACE",
"decl : ident TOKEN_COLON type TOKEN_ASSGN TOKEN_LCURLBRACE n_expr_list_block TOKEN_RCURLBRACE TOKEN_SEMICOLON",
"type : TOKEN_STRING",
"type : TOKEN_INT",
"type : TOKEN_CHAR",
"type : TOKEN_BOOLEAN",
"type : TOKEN_ARRAY TOKEN_LBRACE opt_expr TOKEN_RBRACE type",
"type : TOKEN_FUNCTION type TOKEN_LPAREN param_list TOKEN_RPAREN",
"type : TOKEN_VOID",
"param_list : n_param_list",
"param_list :",
"n_param_list : param",
"n_param_list : param TOKEN_COMMA n_param_list",
"param : ident TOKEN_COLON type",
"ident : TOKEN_IDENT",
"stmt_list : stmt stmt_list",
"stmt_list :",
"stmt : stmt_matched",
"stmt : n_stmt_matched",
"stmt_matched : decl",
"stmt_matched : expr TOKEN_SEMICOLON",
"stmt_matched : TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN stmt_matched",
"stmt_matched : TOKEN_RETURN opt_expr TOKEN_SEMICOLON",
"stmt_matched : TOKEN_PRINT expr_list TOKEN_SEMICOLON",
"stmt_matched : TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt_matched TOKEN_ELSE stmt_matched",
"stmt_matched : stmt_block",
"stmt_block : TOKEN_LCURLBRACE stmt_list TOKEN_RCURLBRACE",
"n_stmt_matched : TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt",
"n_stmt_matched : TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt_matched TOKEN_ELSE n_stmt_matched",
"n_stmt_matched : TOKEN_FOR TOKEN_LPAREN opt_expr TOKEN_SEMICOLON opt_expr TOKEN_SEMICOLON opt_expr TOKEN_RPAREN n_stmt_matched",
"opt_expr : expr",
"opt_expr :",
"expr_list : n_expr_list",
"expr_list :",
"n_expr_list : expr TOKEN_COMMA n_expr_list",
"n_expr_list : expr",
"expr_block : TOKEN_LCURLBRACE n_expr_list_block TOKEN_RCURLBRACE",
"n_expr_list_block : expr_block TOKEN_COMMA n_expr_list_block",
"n_expr_list_block : expr_block",
"n_expr_list_block : n_expr_list",
"expr : expr_not_assgn TOKEN_ASSGN expr",
"expr : expr_not_assgn",
"expr_not_assgn : expr_not_assgn TOKEN_OR expr_and",
"expr_not_assgn : expr_and",
"expr_and : expr_and TOKEN_AND expr_comp",
"expr_and : expr_comp",
"expr_comp : expr_comp TOKEN_LE expr_arith",
"expr_comp : expr_comp TOKEN_GE expr_arith",
"expr_comp : expr_comp TOKEN_LT expr_arith",
"expr_comp : expr_comp TOKEN_GT expr_arith",
"expr_comp : expr_comp TOKEN_EQ expr_arith",
"expr_comp : expr_comp TOKEN_NE expr_arith",
"expr_comp : expr_arith",
"expr_arith : expr_arith TOKEN_ADD expr_geom",
"expr_arith : expr_arith TOKEN_SUB expr_geom",
"expr_arith : expr_geom",
"expr_geom : expr_geom TOKEN_MULT expr_exp",
"expr_geom : expr_geom TOKEN_DIV expr_exp",
"expr_geom : expr_geom TOKEN_MOD expr_exp",
"expr_geom : expr_exp",
"expr_exp : expr_exp TOKEN_EXP expr_unary",
"expr_exp : expr_unary",
"expr_unary : TOKEN_NOT expr_unary",
"expr_unary : TOKEN_SUB expr_unary",
"expr_unary : expr_incr",
"expr_incr : expr_grouping TOKEN_INCREMENT",
"expr_incr : expr_grouping TOKEN_DECREMENT",
"expr_incr : expr_grouping",
"expr_grouping : TOKEN_LPAREN expr TOKEN_RPAREN",
"expr_grouping : ident TOKEN_LBRACE expr TOKEN_RBRACE expr_array",
"expr_grouping : ident TOKEN_LPAREN expr_list TOKEN_RPAREN",
"expr_grouping : expr_primary",
"expr_array : TOKEN_LBRACE expr TOKEN_RBRACE expr_array",
"expr_array :",
"expr_primary : TOKEN_INT_LITERAL",
"expr_primary : ident",
"expr_primary : TOKEN_CHAR_LITERAL",
"expr_primary : TOKEN_TRUE",
"expr_primary : TOKEN_FALSE",
"expr_primary : TOKEN_STRING_LITERAL",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 290 "parser.bison"

int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 1;
}
#line 481 "parser.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 90 "parser.bison"
{parser_result = yyvsp[0].decl;}
break;
case 2:
#line 93 "parser.bison"
{yyval.decl = yyvsp[-1].decl; yyvsp[-1].decl->next = yyvsp[0].decl;}
break;
case 3:
#line 95 "parser.bison"
{yyval.decl = 0;}
break;
case 4:
#line 98 "parser.bison"
{yyval.decl = decl_create(yyvsp[-5].name, yyvsp[-3].type, yyvsp[-1].expr, 0, 0);}
break;
case 5:
#line 100 "parser.bison"
{/*printf("creating decl\n");*/ yyval.decl = decl_create(yyvsp[-3].name, yyvsp[-1].type, 0, 0, 0);}
break;
case 6:
#line 102 "parser.bison"
{yyval.decl = decl_create(yyvsp[-6].name, yyvsp[-4].type, 0, yyvsp[-1].stmt, 0); if(!yyvsp[-1].stmt) {yyval.decl->code = stmt_create(STMT_EMPTY, 0, 0, 0, 0, 0, 0);} /*printf("function\n");*/}
break;
case 7:
#line 104 "parser.bison"
{yyval.decl = decl_create(yyvsp[-7].name, yyvsp[-5].type, yyvsp[-2].expr, 0, 0);}
break;
case 8:
#line 107 "parser.bison"
{yyval.type = type_create(TYPE_STRING, 0, 0, 0);}
break;
case 9:
#line 109 "parser.bison"
{yyval.type = type_create(TYPE_INTEGER, 0, 0, 0);}
break;
case 10:
#line 111 "parser.bison"
{yyval.type = type_create(TYPE_CHARACTER, 0, 0, 0);}
break;
case 11:
#line 113 "parser.bison"
{yyval.type = type_create(TYPE_BOOLEAN, 0, 0, 0);}
break;
case 12:
#line 115 "parser.bison"
{yyval.type = type_create(TYPE_ARRAY, 0, yyvsp[0].type, yyvsp[-2].expr);}
break;
case 13:
#line 117 "parser.bison"
{yyval.type = type_create(TYPE_FUNCTION, yyvsp[-1].param_list, yyvsp[-3].type, 0);}
break;
case 14:
#line 119 "parser.bison"
{yyval.type = type_create(TYPE_VOID, 0, 0, 0);}
break;
case 15:
#line 122 "parser.bison"
{yyval.param_list = yyvsp[0].param_list;}
break;
case 16:
#line 124 "parser.bison"
{yyval.param_list = 0;}
break;
case 17:
#line 127 "parser.bison"
{yyval.param_list = yyvsp[0].param_list;}
break;
case 18:
#line 129 "parser.bison"
{yyval.param_list = yyvsp[-2].param_list; yyvsp[-2].param_list->next = yyvsp[0].param_list;}
break;
case 19:
#line 132 "parser.bison"
{yyval.param_list = param_list_create(yyvsp[-2].name, yyvsp[0].type, 0);}
break;
case 20:
#line 135 "parser.bison"
{char * temp; temp = strdup(yytext); yyval.name = temp;}
break;
case 21:
#line 138 "parser.bison"
{yyval.stmt = yyvsp[-1].stmt; yyvsp[-1].stmt->next = yyvsp[0].stmt;}
break;
case 22:
#line 140 "parser.bison"
{yyval.stmt = 0;}
break;
case 23:
#line 143 "parser.bison"
{yyval.stmt = yyvsp[0].stmt;}
break;
case 24:
#line 145 "parser.bison"
{yyval.stmt = yyvsp[0].stmt;}
break;
case 25:
#line 148 "parser.bison"
{yyval.stmt = stmt_create(STMT_DECL, yyvsp[0].decl, 0, 0, 0, 0, 0);}
break;
case 26:
#line 150 "parser.bison"
{yyval.stmt = stmt_create(STMT_EXPR, 0, 0, yyvsp[-1].expr, 0, 0, 0);}
break;
case 27:
#line 152 "parser.bison"
{yyval.stmt = stmt_create(STMT_FOR, 0, yyvsp[-6].expr, yyvsp[-4].expr, yyvsp[-2].expr, yyvsp[0].stmt, 0);}
break;
case 28:
#line 154 "parser.bison"
{yyval.stmt = stmt_create(STMT_RETURN, 0, 0, yyvsp[-1].expr, 0, 0, 0);}
break;
case 29:
#line 156 "parser.bison"
{yyval.stmt = stmt_create(STMT_PRINT, 0, 0, yyvsp[-1].expr, 0, 0, 0);}
break;
case 30:
#line 158 "parser.bison"
{yyval.stmt = stmt_create(STMT_IF_ELSE, 0, 0, yyvsp[-4].expr, 0, yyvsp[-2].stmt, yyvsp[0].stmt);}
break;
case 31:
#line 160 "parser.bison"
{yyval.stmt = yyvsp[0].stmt;}
break;
case 32:
#line 163 "parser.bison"
{yyval.stmt = stmt_create(STMT_BLOCK, 0, 0, 0, 0, yyvsp[-1].stmt, 0);}
break;
case 33:
#line 166 "parser.bison"
{yyval.stmt = stmt_create(STMT_IF_ELSE, 0, 0, yyvsp[-2].expr, 0, yyvsp[0].stmt, 0); /*printf("gotem\n");*/}
break;
case 34:
#line 168 "parser.bison"
{yyval.stmt = stmt_create(STMT_IF_ELSE, 0, 0, yyvsp[-4].expr, 0, yyvsp[-2].stmt, yyvsp[0].stmt); /*printf("gotem\n");*/}
break;
case 35:
#line 170 "parser.bison"
{yyval.stmt = stmt_create(STMT_FOR, 0, yyvsp[-6].expr, yyvsp[-4].expr, yyvsp[-2].expr, yyvsp[0].stmt, 0);}
break;
case 36:
#line 173 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 37:
#line 175 "parser.bison"
{yyval.expr = 0;}
break;
case 38:
#line 178 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 39:
#line 180 "parser.bison"
{yyval.expr = 0;}
break;
case 40:
#line 183 "parser.bison"
{yyval.expr = expr_create(EXPR_LIST, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 41:
#line 185 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 42:
#line 188 "parser.bison"
{yyval.expr = expr_create(EXPR_BLOCK, yyvsp[-1].expr, 0);}
break;
case 43:
#line 191 "parser.bison"
{yyval.expr = expr_create(EXPR_BLOCK, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 44:
#line 193 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 45:
#line 195 "parser.bison"
{yyval.expr = expr_create(EXPR_BLOCK, yyvsp[0].expr, 0);}
break;
case 46:
#line 198 "parser.bison"
{yyval.expr = expr_create(EXPR_ASSGN, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 47:
#line 200 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 48:
#line 203 "parser.bison"
{yyval.expr = expr_create(EXPR_OR, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 49:
#line 205 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 50:
#line 208 "parser.bison"
{yyval.expr = expr_create(EXPR_AND, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 51:
#line 210 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 52:
#line 213 "parser.bison"
{yyval.expr = expr_create(EXPR_LE, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 53:
#line 215 "parser.bison"
{yyval.expr = expr_create(EXPR_GE, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 54:
#line 217 "parser.bison"
{yyval.expr = expr_create(EXPR_LT, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 55:
#line 219 "parser.bison"
{yyval.expr = expr_create(EXPR_GT, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 56:
#line 221 "parser.bison"
{yyval.expr = expr_create(EXPR_EQ, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 57:
#line 223 "parser.bison"
{yyval.expr = expr_create(EXPR_NE, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 58:
#line 225 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 59:
#line 228 "parser.bison"
{yyval.expr = expr_create(EXPR_ADD, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 60:
#line 230 "parser.bison"
{yyval.expr = expr_create(EXPR_SUB, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 61:
#line 232 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 62:
#line 235 "parser.bison"
{yyval.expr = expr_create(EXPR_MULT, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 63:
#line 237 "parser.bison"
{yyval.expr = expr_create(EXPR_DIV, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 64:
#line 239 "parser.bison"
{yyval.expr = expr_create(EXPR_MOD, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 65:
#line 241 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 66:
#line 244 "parser.bison"
{yyval.expr = expr_create(EXPR_EXP, yyvsp[-2].expr, yyvsp[0].expr);}
break;
case 67:
#line 246 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 68:
#line 249 "parser.bison"
{yyval.expr = expr_create(EXPR_NOT, 0, yyvsp[0].expr);}
break;
case 69:
#line 251 "parser.bison"
{yyval.expr = expr_create(EXPR_NEG, 0, yyvsp[0].expr);}
break;
case 70:
#line 253 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 71:
#line 256 "parser.bison"
{yyval.expr = expr_create(EXPR_INCR, yyvsp[-1].expr, 0);}
break;
case 72:
#line 258 "parser.bison"
{yyval.expr = expr_create(EXPR_DECR, yyvsp[-1].expr, 0);}
break;
case 73:
#line 260 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 74:
#line 263 "parser.bison"
{yyval.expr = yyvsp[-1].expr;}
break;
case 75:
#line 265 "parser.bison"
{yyval.expr = expr_create(EXPR_BRACKET, expr_create_name(yyvsp[-4].name), yyvsp[-2].expr);}
break;
case 76:
#line 267 "parser.bison"
{yyval.expr = expr_create(EXPR_FUNC, expr_create_name(yyvsp[-3].name), yyvsp[-1].expr);}
break;
case 77:
#line 269 "parser.bison"
{yyval.expr = yyvsp[0].expr;}
break;
case 80:
#line 275 "parser.bison"
{int temp = atoi(yytext); yyval.expr = expr_create_integer_literal(temp);/*printf("%d\n", $$->literal_value);*/}
break;
case 81:
#line 277 "parser.bison"
{yyval.expr = expr_create_name(yyvsp[0].name);}
break;
case 82:
#line 279 "parser.bison"
{yyval.expr = expr_create_character_literal((yytext[0])); }
break;
case 83:
#line 281 "parser.bison"
{yyval.expr = expr_create_boolean_literal(1);}
break;
case 84:
#line 283 "parser.bison"
{yyval.expr = expr_create_boolean_literal(0);}
break;
case 85:
#line 285 "parser.bison"
{char * temp; temp = strdup(yytext); yyval.expr = expr_create_string_literal(temp);}
break;
#line 994 "parser.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
