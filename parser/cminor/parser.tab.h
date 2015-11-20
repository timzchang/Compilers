/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_IDENT = 258,
     TOKEN_STRING = 259,
     TOKEN_STRING_LITERAL = 260,
     TOKEN_INT = 261,
     TOKEN_INT_LITERAL = 262,
     TOKEN_IF = 263,
     TOKEN_ARRAY = 264,
     TOKEN_BOOLEAN = 265,
     TOKEN_CHAR = 266,
     TOKEN_CHAR_LITERAL = 267,
     TOKEN_ELSE = 268,
     TOKEN_FALSE = 269,
     TOKEN_FOR = 270,
     TOKEN_FUNCTION = 271,
     TOKEN_PRINT = 272,
     TOKEN_RETURN = 273,
     TOKEN_TRUE = 274,
     TOKEN_VOID = 275,
     TOKEN_WHILE = 276,
     TOKEN_ADD = 277,
     TOKEN_SUB = 278,
     TOKEN_MULT = 279,
     TOKEN_DIV = 280,
     TOKEN_MOD = 281,
     TOKEN_EXP = 282,
     TOKEN_INCREMENT = 283,
     TOKEN_DECREMENT = 284,
     TOKEN_NEGATION = 285,
     TOKEN_GT = 286,
     TOKEN_GE = 287,
     TOKEN_EQ = 288,
     TOKEN_LE = 289,
     TOKEN_LT = 290,
     TOKEN_AND = 291,
     TOKEN_OR = 292,
     TOKEN_NE = 293,
     TOKEN_ASSGN = 294,
     TOKEN_SEMICOLON = 295,
     TOKEN_COLON = 296,
     TOKEN_LPAREN = 297,
     TOKEN_RPAREN = 298,
     TOKEN_LBRACE = 299,
     TOKEN_RBRACE = 300,
     TOKEN_LCURLBRACE = 301,
     TOKEN_RCURLBRACE = 302,
     TOKEN_COMMA = 303,
     TOKEN_NOT = 304,
     NOT_TOKEN = 305
   };
#endif
/* Tokens.  */
#define TOKEN_IDENT 258
#define TOKEN_STRING 259
#define TOKEN_STRING_LITERAL 260
#define TOKEN_INT 261
#define TOKEN_INT_LITERAL 262
#define TOKEN_IF 263
#define TOKEN_ARRAY 264
#define TOKEN_BOOLEAN 265
#define TOKEN_CHAR 266
#define TOKEN_CHAR_LITERAL 267
#define TOKEN_ELSE 268
#define TOKEN_FALSE 269
#define TOKEN_FOR 270
#define TOKEN_FUNCTION 271
#define TOKEN_PRINT 272
#define TOKEN_RETURN 273
#define TOKEN_TRUE 274
#define TOKEN_VOID 275
#define TOKEN_WHILE 276
#define TOKEN_ADD 277
#define TOKEN_SUB 278
#define TOKEN_MULT 279
#define TOKEN_DIV 280
#define TOKEN_MOD 281
#define TOKEN_EXP 282
#define TOKEN_INCREMENT 283
#define TOKEN_DECREMENT 284
#define TOKEN_NEGATION 285
#define TOKEN_GT 286
#define TOKEN_GE 287
#define TOKEN_EQ 288
#define TOKEN_LE 289
#define TOKEN_LT 290
#define TOKEN_AND 291
#define TOKEN_OR 292
#define TOKEN_NE 293
#define TOKEN_ASSGN 294
#define TOKEN_SEMICOLON 295
#define TOKEN_COLON 296
#define TOKEN_LPAREN 297
#define TOKEN_RPAREN 298
#define TOKEN_LBRACE 299
#define TOKEN_RBRACE 300
#define TOKEN_LCURLBRACE 301
#define TOKEN_RCURLBRACE 302
#define TOKEN_COMMA 303
#define TOKEN_NOT 304
#define NOT_TOKEN 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 1 "parser.bison"
{
	struct decl *decl;
	struct stmt *stmt;
	struct expr *expr;
	struct type *type;
	char *name;
	struct param_list *param_list;
}
/* Line 1529 of yacc.c.  */
#line 158 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

