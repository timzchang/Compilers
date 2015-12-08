/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 206 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 64 "parser.bison"

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



/* Line 216 of yacc.c.  */
#line 241 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    16,    21,    29,    38,
      40,    42,    44,    46,    52,    58,    60,    62,    63,    65,
      69,    73,    75,    78,    79,    81,    83,    85,    88,    98,
     102,   106,   114,   116,   120,   126,   134,   144,   146,   147,
     149,   150,   154,   156,   160,   164,   166,   168,   172,   174,
     178,   180,   184,   186,   190,   194,   198,   202,   206,   210,
     212,   216,   220,   222,   226,   230,   234,   236,   240,   242,
     245,   248,   250,   253,   256,   258,   262,   268,   273,   275,
     280,   281,   283,   285,   287,   289,   291
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    54,    53,    -1,    -1,    59,
      41,    55,    39,    70,    40,    -1,    59,    41,    55,    40,
      -1,    59,    41,    55,    39,    46,    60,    47,    -1,    59,
      41,    55,    39,    46,    69,    47,    40,    -1,     4,    -1,
       6,    -1,    11,    -1,    10,    -1,     9,    44,    65,    45,
      55,    -1,    16,    55,    42,    56,    43,    -1,    20,    -1,
      57,    -1,    -1,    58,    -1,    58,    48,    57,    -1,    59,
      41,    55,    -1,     3,    -1,    61,    60,    -1,    -1,    62,
      -1,    64,    -1,    54,    -1,    70,    40,    -1,    15,    42,
      65,    40,    65,    40,    65,    43,    62,    -1,    18,    65,
      40,    -1,    17,    66,    40,    -1,     8,    42,    70,    43,
      62,    13,    62,    -1,    63,    -1,    46,    60,    47,    -1,
       8,    42,    70,    43,    61,    -1,     8,    42,    70,    43,
      62,    13,    64,    -1,    15,    42,    65,    40,    65,    40,
      65,    43,    64,    -1,    70,    -1,    -1,    67,    -1,    -1,
      70,    48,    67,    -1,    70,    -1,    46,    69,    47,    -1,
      68,    48,    69,    -1,    68,    -1,    67,    -1,    70,    39,
      71,    -1,    71,    -1,    71,    37,    72,    -1,    72,    -1,
      72,    36,    73,    -1,    73,    -1,    73,    34,    74,    -1,
      73,    32,    74,    -1,    73,    35,    74,    -1,    73,    31,
      74,    -1,    73,    33,    74,    -1,    73,    38,    74,    -1,
      74,    -1,    74,    22,    75,    -1,    74,    23,    75,    -1,
      75,    -1,    75,    24,    76,    -1,    75,    25,    76,    -1,
      75,    26,    76,    -1,    76,    -1,    76,    27,    77,    -1,
      77,    -1,    49,    77,    -1,    30,    77,    -1,    78,    -1,
      79,    28,    -1,    79,    29,    -1,    79,    -1,    42,    70,
      43,    -1,    59,    44,    70,    45,    80,    -1,    59,    42,
      66,    43,    -1,    81,    -1,    44,    70,    45,    80,    -1,
      -1,     7,    -1,    59,    -1,    12,    -1,    19,    -1,    14,
      -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    92,    95,    97,    99,   101,   103,   106,
     108,   110,   112,   114,   116,   118,   121,   124,   126,   128,
     131,   134,   137,   140,   142,   144,   147,   149,   151,   153,
     155,   157,   159,   162,   165,   167,   169,   172,   175,   177,
     180,   182,   184,   187,   190,   192,   194,   197,   199,   202,
     204,   207,   209,   212,   214,   216,   218,   220,   222,   224,
     227,   229,   231,   234,   236,   238,   240,   243,   245,   248,
     250,   252,   255,   257,   259,   262,   264,   266,   268,   271,
     272,   274,   276,   278,   280,   282,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_IDENT", "TOKEN_STRING",
  "TOKEN_STRING_LITERAL", "TOKEN_INT", "TOKEN_INT_LITERAL", "TOKEN_IF",
  "TOKEN_ARRAY", "TOKEN_BOOLEAN", "TOKEN_CHAR", "TOKEN_CHAR_LITERAL",
  "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FOR", "TOKEN_FUNCTION",
  "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_TRUE", "TOKEN_VOID", "TOKEN_WHILE",
  "TOKEN_ADD", "TOKEN_SUB", "TOKEN_MULT", "TOKEN_DIV", "TOKEN_MOD",
  "TOKEN_EXP", "TOKEN_INCREMENT", "TOKEN_DECREMENT", "TOKEN_NEGATION",
  "TOKEN_GT", "TOKEN_GE", "TOKEN_EQ", "TOKEN_LE", "TOKEN_LT", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_NE", "TOKEN_ASSGN", "TOKEN_SEMICOLON", "TOKEN_COLON",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACE", "TOKEN_RBRACE",
  "TOKEN_LCURLBRACE", "TOKEN_RCURLBRACE", "TOKEN_COMMA", "TOKEN_NOT",
  "NOT_TOKEN", "$accept", "program", "decl_list", "decl", "type",
  "param_list", "n_param_list", "param", "ident", "stmt_list", "stmt",
  "stmt_matched", "stmt_block", "n_stmt_matched", "opt_expr", "expr_list",
  "n_expr_list", "expr_block", "n_expr_list_block", "expr",
  "expr_not_assgn", "expr_and", "expr_comp", "expr_arith", "expr_geom",
  "expr_exp", "expr_unary", "expr_incr", "expr_grouping", "expr_array",
  "expr_primary", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    78,    78,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     4,     7,     8,     1,
       1,     1,     1,     5,     5,     1,     1,     0,     1,     3,
       3,     1,     2,     0,     1,     1,     1,     2,     9,     3,
       3,     7,     1,     3,     5,     7,     9,     1,     0,     1,
       0,     3,     1,     3,     3,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     2,
       2,     1,     2,     2,     1,     3,     5,     4,     1,     4,
       0,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    21,     0,     2,     4,     0,     1,     3,     0,     9,
      10,     0,    12,    11,     0,    15,     0,    38,     0,     0,
       6,    86,    81,    83,    85,    84,     0,     0,     0,    82,
       0,    37,    48,    50,    52,    59,    62,    66,    68,    71,
      74,    78,    17,    23,     0,    70,     0,    69,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,    16,
      18,     0,     0,     0,    40,    38,    23,    26,    82,     0,
      23,    24,    32,    25,    46,    45,     0,    42,     5,    75,
       0,    39,    42,     0,    13,    47,    49,    51,    56,    54,
      57,    53,    55,    58,    60,    61,    63,    64,    65,    67,
      14,     0,     0,     0,    38,     0,     0,     0,     0,     7,
      23,    22,     0,     0,     0,    27,     0,    77,    80,    19,
      20,     0,     0,    30,    29,    33,    43,     0,    44,     8,
      41,     0,    76,     0,    38,     0,    34,    24,     0,    80,
       0,    38,    79,    31,    35,     0,     0,    28,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    77,    16,    68,    69,    70,    29,   117,
      80,    81,    82,    83,    30,    90,    84,    85,   118,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   142,
      41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -130
static const yytype_int16 yypact[] =
{
       4,  -130,    26,  -130,     4,     9,  -130,  -130,   162,  -130,
    -130,    19,  -130,  -130,   162,  -130,    67,   134,    11,    85,
    -130,  -130,  -130,  -130,  -130,  -130,   134,   134,   134,    47,
      23,    38,    56,    60,   127,    87,    61,    76,  -130,  -130,
      88,  -130,     4,     5,    82,  -130,     2,  -130,   134,   134,
     162,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,  -130,  -130,    93,  -130,
      70,   101,   105,   107,   134,   134,     5,  -130,   -26,   108,
      52,  -130,  -130,  -130,  -130,   104,   110,   -11,  -130,  -130,
     111,  -130,     1,    -6,  -130,    56,    60,   127,    87,    87,
      87,    87,    87,    87,    61,    61,    76,    76,    76,  -130,
    -130,     4,   162,   134,   134,   129,   135,   132,   133,  -130,
      52,  -130,    90,   121,   137,  -130,   134,  -130,   146,  -130,
    -130,    22,   141,  -130,  -130,  -130,  -130,   121,  -130,  -130,
    -130,   134,  -130,    52,   134,     7,  -130,   161,   151,   146,
      52,   134,  -130,  -130,  -130,   149,    52,  -130,  -130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   189,    75,   -12,  -130,    83,  -130,     0,   -32,
      53,  -129,  -130,   -78,   -70,   123,   -42,  -130,   -40,   -18,
     144,   147,   145,   130,    84,    50,     8,  -130,  -130,    51,
    -130
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       5,    44,    18,    86,     5,   116,    91,     1,     1,    46,
      21,    79,    22,    72,   147,     8,    48,    23,    49,    24,
      73,   153,    74,    75,    25,    87,     6,   157,    51,   125,
      92,    93,    91,    51,    45,    26,    47,   126,    94,   128,
      51,    51,    71,    78,   132,    89,    51,    27,   121,   126,
       8,    76,   149,    42,    28,     1,    92,    21,    87,    22,
      72,    51,   122,    17,    23,   143,    24,    73,    50,    74,
      75,    25,   154,   109,   148,     4,    78,    51,   158,     4,
      78,   155,    26,   138,   140,    62,    63,    64,     1,    48,
      21,    49,    22,    52,    27,   131,    53,    23,   120,    24,
     130,    28,   122,    65,    25,    92,    19,    20,    92,    60,
      61,    71,   106,   107,   108,    26,    66,    67,   111,    92,
      78,    51,    88,   145,     1,   122,    21,    27,    22,    51,
     125,    43,   122,    23,    28,    24,   110,     1,   122,    21,
      25,    22,   112,    78,   104,   105,    23,   113,    24,   114,
      78,    26,   123,    25,   127,   119,    78,   124,    54,    55,
      56,    57,    58,    27,    26,    59,     9,   137,    10,   133,
      28,    11,    12,    13,   150,   134,    27,   139,    14,   135,
     136,   144,    15,    28,    98,    99,   100,   101,   102,   103,
     141,   151,   156,     7,   129,    95,   146,   115,    97,    96,
     152
};

static const yytype_uint8 yycheck[] =
{
       0,    19,    14,    43,     4,    75,    48,     3,     3,    27,
       5,    43,     7,     8,   143,    41,    42,    12,    44,    14,
      15,   150,    17,    18,    19,    43,     0,   156,    39,    40,
      48,    49,    74,    39,    26,    30,    28,    48,    50,    45,
      39,    39,    42,    43,   114,    43,    39,    42,    80,    48,
      41,    46,    45,    42,    49,     3,    74,     5,    76,     7,
       8,    39,    80,    44,    12,    43,    14,    15,    45,    17,
      18,    19,   150,    65,   144,     0,    76,    39,   156,     4,
      80,   151,    30,   123,   126,    24,    25,    26,     3,    42,
       5,    44,     7,    37,    42,   113,    36,    12,    46,    14,
     112,    49,   120,    27,    19,   123,    39,    40,   126,    22,
      23,   111,    62,    63,    64,    30,    28,    29,    48,   137,
     120,    39,    40,   141,     3,   143,     5,    42,     7,    39,
      40,    46,   150,    12,    49,    14,    43,     3,   156,     5,
      19,     7,    41,   143,    60,    61,    12,    42,    14,    42,
     150,    30,    48,    19,    43,    47,   156,    47,    31,    32,
      33,    34,    35,    42,    30,    38,     4,    46,     6,    40,
      49,     9,    10,    11,    13,    40,    42,    40,    16,    47,
      47,    40,    20,    49,    54,    55,    56,    57,    58,    59,
      44,    40,    43,     4,   111,    51,   143,    74,    53,    52,
     149
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    53,    54,    59,     0,    53,    41,     4,
       6,     9,    10,    11,    16,    20,    55,    44,    55,    39,
      40,     5,     7,    12,    14,    19,    30,    42,    49,    59,
      65,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    81,    42,    46,    70,    77,    70,    77,    42,    44,
      45,    39,    37,    36,    31,    32,    33,    34,    35,    38,
      22,    23,    24,    25,    26,    27,    28,    29,    56,    57,
      58,    59,     8,    15,    17,    18,    46,    54,    59,    60,
      61,    62,    63,    64,    67,    68,    69,    70,    40,    43,
      66,    67,    70,    70,    55,    71,    72,    73,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    76,    77,
      43,    48,    41,    42,    42,    66,    65,    60,    69,    47,
      46,    60,    70,    48,    47,    40,    48,    43,    45,    57,
      55,    70,    65,    40,    40,    47,    47,    46,    69,    40,
      67,    44,    80,    43,    40,    70,    61,    62,    65,    45,
      13,    40,    80,    62,    64,    65,    43,    62,    64
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 90 "parser.bison"
    {parser_result = (yyvsp[(1) - (1)].decl);}
    break;

  case 3:
#line 93 "parser.bison"
    {(yyval.decl) = (yyvsp[(1) - (2)].decl); (yyvsp[(1) - (2)].decl)->next = (yyvsp[(2) - (2)].decl);}
    break;

  case 4:
#line 95 "parser.bison"
    {(yyval.decl) = 0;}
    break;

  case 5:
#line 98 "parser.bison"
    {(yyval.decl) = decl_create((yyvsp[(1) - (6)].name), (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].expr), 0, 0);}
    break;

  case 6:
#line 100 "parser.bison"
    {/*printf("creating decl\n");*/ (yyval.decl) = decl_create((yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].type), 0, 0, 0);}
    break;

  case 7:
#line 102 "parser.bison"
    {(yyval.decl) = decl_create((yyvsp[(1) - (7)].name), (yyvsp[(3) - (7)].type), 0, (yyvsp[(6) - (7)].stmt), 0); if(!(yyvsp[(6) - (7)].stmt)) {(yyval.decl)->code = stmt_create(STMT_EMPTY, 0, 0, 0, 0, 0, 0);} /*printf("function\n");*/}
    break;

  case 8:
#line 104 "parser.bison"
    {(yyval.decl) = decl_create((yyvsp[(1) - (8)].name), (yyvsp[(3) - (8)].type), (yyvsp[(6) - (8)].expr), 0, 0);}
    break;

  case 9:
#line 107 "parser.bison"
    {(yyval.type) = type_create(TYPE_STRING, 0, 0, 0);}
    break;

  case 10:
#line 109 "parser.bison"
    {(yyval.type) = type_create(TYPE_INTEGER, 0, 0, 0);}
    break;

  case 11:
#line 111 "parser.bison"
    {(yyval.type) = type_create(TYPE_CHARACTER, 0, 0, 0);}
    break;

  case 12:
#line 113 "parser.bison"
    {(yyval.type) = type_create(TYPE_BOOLEAN, 0, 0, 0);}
    break;

  case 13:
#line 115 "parser.bison"
    {(yyval.type) = type_create(TYPE_ARRAY, 0, (yyvsp[(5) - (5)].type), (yyvsp[(3) - (5)].expr));}
    break;

  case 14:
#line 117 "parser.bison"
    {(yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[(4) - (5)].param_list), (yyvsp[(2) - (5)].type), 0);}
    break;

  case 15:
#line 119 "parser.bison"
    {(yyval.type) = type_create(TYPE_VOID, 0, 0, 0);}
    break;

  case 16:
#line 122 "parser.bison"
    {(yyval.param_list) = (yyvsp[(1) - (1)].param_list);}
    break;

  case 17:
#line 124 "parser.bison"
    {(yyval.param_list) = 0;}
    break;

  case 18:
#line 127 "parser.bison"
    {(yyval.param_list) = (yyvsp[(1) - (1)].param_list);}
    break;

  case 19:
#line 129 "parser.bison"
    {(yyval.param_list) = (yyvsp[(1) - (3)].param_list); (yyvsp[(1) - (3)].param_list)->next = (yyvsp[(3) - (3)].param_list);}
    break;

  case 20:
#line 132 "parser.bison"
    {(yyval.param_list) = param_list_create((yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].type), 0);}
    break;

  case 21:
#line 135 "parser.bison"
    {char * temp; temp = strdup(yytext); (yyval.name) = temp;}
    break;

  case 22:
#line 138 "parser.bison"
    {(yyval.stmt) = (yyvsp[(1) - (2)].stmt); (yyvsp[(1) - (2)].stmt)->next = (yyvsp[(2) - (2)].stmt);}
    break;

  case 23:
#line 140 "parser.bison"
    {(yyval.stmt) = 0;}
    break;

  case 24:
#line 143 "parser.bison"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 25:
#line 145 "parser.bison"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 26:
#line 148 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[(1) - (1)].decl), 0, 0, 0, 0, 0);}
    break;

  case 27:
#line 150 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0);}
    break;

  case 28:
#line 152 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt), 0);}
    break;

  case 29:
#line 154 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0);}
    break;

  case 30:
#line 156 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0);}
    break;

  case 31:
#line 158 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(3) - (7)].expr), 0, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));}
    break;

  case 32:
#line 160 "parser.bison"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);}
    break;

  case 33:
#line 163 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[(2) - (3)].stmt), 0);}
    break;

  case 34:
#line 166 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(3) - (5)].expr), 0, (yyvsp[(5) - (5)].stmt), 0); /*printf("gotem\n");*/}
    break;

  case 35:
#line 168 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(3) - (7)].expr), 0, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt)); /*printf("gotem\n");*/}
    break;

  case 36:
#line 170 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt), 0);}
    break;

  case 37:
#line 173 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 38:
#line 175 "parser.bison"
    {(yyval.expr) = 0;}
    break;

  case 39:
#line 178 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 40:
#line 180 "parser.bison"
    {(yyval.expr) = 0;}
    break;

  case 41:
#line 183 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_LIST, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 42:
#line 185 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 43:
#line 188 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_BLOCK, (yyvsp[(2) - (3)].expr), 0);}
    break;

  case 44:
#line 191 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_BLOCK, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 45:
#line 193 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 46:
#line 195 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_BLOCK, (yyvsp[(1) - (1)].expr), 0);}
    break;

  case 47:
#line 198 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_ASSGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 48:
#line 200 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 49:
#line 203 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 50:
#line 205 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 51:
#line 208 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 52:
#line 210 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 53:
#line 213 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_LE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 54:
#line 215 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_GE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 55:
#line 217 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 56:
#line 219 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 57:
#line 221 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 58:
#line 223 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_NE, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 59:
#line 225 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 60:
#line 228 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 61:
#line 230 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 62:
#line 232 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 63:
#line 235 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_MULT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 64:
#line 237 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 65:
#line 239 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 66:
#line 241 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 67:
#line 244 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_EXP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));}
    break;

  case 68:
#line 246 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 69:
#line 249 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_NOT, 0, (yyvsp[(2) - (2)].expr));}
    break;

  case 70:
#line 251 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_NEG, 0, (yyvsp[(2) - (2)].expr));}
    break;

  case 71:
#line 253 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 72:
#line 256 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_INCR, (yyvsp[(1) - (2)].expr), 0);}
    break;

  case 73:
#line 258 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_DECR, (yyvsp[(1) - (2)].expr), 0);}
    break;

  case 74:
#line 260 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 75:
#line 263 "parser.bison"
    {(yyval.expr) = (yyvsp[(2) - (3)].expr);}
    break;

  case 76:
#line 265 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_BRACKET, expr_create_name((yyvsp[(1) - (5)].name)), (yyvsp[(3) - (5)].expr));}
    break;

  case 77:
#line 267 "parser.bison"
    {(yyval.expr) = expr_create(EXPR_FUNC, expr_create_name((yyvsp[(1) - (4)].name)), (yyvsp[(3) - (4)].expr));}
    break;

  case 78:
#line 269 "parser.bison"
    {(yyval.expr) = (yyvsp[(1) - (1)].expr);}
    break;

  case 81:
#line 275 "parser.bison"
    {int temp = atoi(yytext); (yyval.expr) = expr_create_integer_literal(temp);/*printf("%d\n", $$->literal_value);*/}
    break;

  case 82:
#line 277 "parser.bison"
    {(yyval.expr) = expr_create_name((yyvsp[(1) - (1)].name));}
    break;

  case 83:
#line 279 "parser.bison"
    {(yyval.expr) = expr_create_character_literal((yytext[0])); }
    break;

  case 84:
#line 281 "parser.bison"
    {(yyval.expr) = expr_create_boolean_literal(1);}
    break;

  case 85:
#line 283 "parser.bison"
    {(yyval.expr) = expr_create_boolean_literal(0);}
    break;

  case 86:
#line 285 "parser.bison"
    {char * temp; temp = strdup(yytext); (yyval.expr) = expr_create_string_literal(temp);}
    break;


/* Line 1267 of yacc.c.  */
#line 2013 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 289 "parser.bison"


int yyerror( char *str )
{
	printf("parse error: %s\n",str);
	return 1;
}

