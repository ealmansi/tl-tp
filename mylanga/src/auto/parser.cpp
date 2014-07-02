/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "src/parser.y"


#include <list>
#include <iostream>
using namespace std;

#include "mylanga_fp_t.h"
#include "mylanga_ast.h"
#include "mylanga_sem_types.h"
#include "mylanga_error.h"
#define YYSTYPE mylanga_sem_types

extern int line_num; int temp;
extern ptr<ast_program> pg;

extern int yylex();
void yyerror(const char *s) { cerr << MYLANGA_SYNTAX_ERROR(line_num) << endl; }



/* Line 268 of yacc.c  */
#line 92 "src/auto/parser.cpp"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INT_LITERAL = 259,
     FP_LITERAL = 260,
     KW_FOR = 261,
     KW_PLOT = 262,
     KW_IF = 263,
     KW_THEN = 264,
     KW_ELSE = 265,
     KW_WHILE = 266,
     KW_RETURN = 267,
     KW_FUNCTION = 268,
     KW_PI = 269,
     EQUAL = 270,
     COMMA = 271,
     SEMICOLON = 272,
     ELLIPSIS = 273,
     L_OR = 274,
     L_AND = 275,
     L_NOT = 276,
     REL_EQ = 277,
     REL_LT = 278,
     REL_LEQ = 279,
     REL_GEQ = 280,
     REL_GT = 281,
     LPAREN = 282,
     RPAREN = 283,
     LBRACE = 284,
     RBRACE = 285,
     OP_PLUS = 286,
     OP_MINUS = 287,
     OP_MULT = 288,
     OP_DIV = 289,
     OP_EXP = 290,
     UMINUS = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 169 "src/auto/parser.cpp"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   425

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    11,    18,    24,    39,
      50,    57,    59,    63,    66,    70,    75,    82,    86,    89,
      93,    97,    98,   106,   107,   112,   113,   118,   121,   124,
     127,   129,   131,   133,   135,   139,   143,   147,   151,   154,
     158,   163,   167,   171,   175,   179,   183,   187,   191,   195,
     199,   203,   207,   211,   215,   219,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   257,   259,   262,   264,   267,
     268,   270,   272,   276,   277,   279,   281
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    48,    40,    -1,    48,    -1,    40,    -1,
      -1,    13,     3,    27,    50,    28,    41,    -1,    13,     3,
      27,    50,    28,    -1,     7,    27,    46,    16,    46,    28,
       6,     3,    15,    46,    18,    46,    18,    46,    -1,     7,
      46,     6,     3,    15,    46,    18,    46,    18,    46,    -1,
       7,    27,    46,    16,    46,    28,    -1,    42,    -1,    29,
      49,    30,    -1,    29,    30,    -1,     3,    15,    46,    -1,
       8,    47,     9,    41,    -1,     8,    47,     9,    41,    10,
      41,    -1,    11,    47,    41,    -1,    12,    46,    -1,     1,
      15,    46,    -1,     3,    15,     1,    -1,    -1,     8,    46,
      43,     9,    41,    10,    41,    -1,    -1,    11,    46,    44,
      41,    -1,    -1,     8,    47,    45,    41,    -1,     8,     1,
      -1,    11,     1,    -1,    12,     1,    -1,     4,    -1,     5,
      -1,    14,    -1,     3,    -1,    46,    31,    46,    -1,    46,
      32,    46,    -1,    46,    33,    46,    -1,    46,    34,    46,
      -1,    32,    46,    -1,    46,    35,    46,    -1,     3,    27,
      52,    28,    -1,    27,    46,    28,    -1,    46,    31,     1,
      -1,    46,    32,     1,    -1,    46,    33,     1,    -1,    46,
      34,     1,    -1,    46,    35,     1,    -1,    27,     1,    28,
      -1,    46,    23,    46,    -1,    46,    24,    46,    -1,    46,
      22,    46,    -1,    46,    25,    46,    -1,    46,    26,    46,
      -1,    47,    19,    47,    -1,    47,    20,    47,    -1,    21,
      47,    -1,    27,    47,    28,    -1,    46,    23,     1,    -1,
      46,    24,     1,    -1,    46,    22,     1,    -1,    46,    25,
       1,    -1,    46,    26,     1,    -1,    47,    19,     1,    -1,
      47,    20,     1,    -1,    21,     1,    -1,    39,    -1,    48,
      39,    -1,    42,    -1,    49,    42,    -1,    -1,    51,    -1,
       3,    -1,    51,    16,     3,    -1,    -1,    53,    -1,    46,
      -1,    53,    16,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    78,    79,    80,    84,    88,    93,    98,
     101,   106,   107,   110,   114,   115,   116,   117,   118,   121,
     122,   123,   123,   124,   124,   125,   125,   126,   127,   128,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   146,   147,   148,   149,   150,   151,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   166,   167,   168,
     169,   170,   171,   172,   173,   177,   178,   182,   183,   187,
     188,   192,   193,   197,   198,   202,   203
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT_LITERAL", "FP_LITERAL",
  "KW_FOR", "KW_PLOT", "KW_IF", "KW_THEN", "KW_ELSE", "KW_WHILE",
  "KW_RETURN", "KW_FUNCTION", "KW_PI", "EQUAL", "COMMA", "SEMICOLON",
  "ELLIPSIS", "L_OR", "L_AND", "L_NOT", "REL_EQ", "REL_LT", "REL_LEQ",
  "REL_GEQ", "REL_GT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "OP_PLUS",
  "OP_MINUS", "OP_MULT", "OP_DIV", "OP_EXP", "UMINUS", "$accept",
  "program", "fun_def", "plot_cmd", "block", "stmt", "$@1", "$@2", "$@3",
  "expr", "pred", "seq_fun_def", "seq_stmt", "lst_id", "_lst_id",
  "lst_expr", "_lst_expr", 0
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    39,    39,    40,    40,
      40,    41,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    43,    42,    44,    42,    45,    42,    42,    42,    42,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     6,     5,    14,    10,
       6,     1,     3,     2,     3,     4,     6,     3,     2,     3,
       3,     0,     7,     0,     4,     0,     4,     2,     2,     2,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     2,     1,     2,     0,
       1,     1,     3,     0,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,    65,     4,     3,    33,    30,    31,
      32,     0,     0,     0,     0,     1,    66,     2,    73,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,    69,
      75,     0,    74,    47,     0,     0,    41,     0,    42,    34,
      43,    35,    44,    36,    45,    37,    46,    39,    71,     0,
      70,    40,     0,     0,     0,     0,     0,    76,    10,     0,
       0,     0,     0,     0,     0,     0,     6,    11,    72,     0,
       0,     0,     0,    27,     0,     0,    21,    25,    28,    23,
       0,    29,    18,    13,    67,     0,     0,     0,    19,    20,
      14,    64,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    12,    68,
       0,     0,    56,    59,    50,    57,    48,    58,    49,    60,
      51,    61,    52,     0,    15,    62,    53,    63,    54,    26,
      24,     0,     9,     0,     0,     0,     0,    16,     0,    22,
       0,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    66,    67,   101,   106,   105,    92,
      77,     6,    85,    49,    50,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
       7,     4,     0,    16,   -63,   -63,     7,     2,   -63,   -63,
     -63,   152,    54,   164,     3,   -63,   -63,   -63,    54,    11,
     152,   330,    -3,    32,   159,   173,   189,   203,   209,    64,
     390,    45,    60,   -63,   377,    54,   -63,    69,   -63,    95,
     -63,    95,   -63,    -3,   -63,    -3,   -63,   -63,   -63,    57,
      63,   -63,    54,   385,    54,    37,    85,   390,    88,   214,
      87,    91,     1,    51,   223,   311,   -63,   -63,   -63,   105,
      54,    54,   239,   -63,    86,   100,   369,    73,   -63,   369,
     331,   -63,   390,   -63,   -63,   317,    96,   264,   390,   -63,
     390,   -63,   369,   -63,   355,    97,   253,   259,   273,   289,
     303,   103,   337,   119,   140,   337,   337,   -63,   -63,   -63,
      54,    54,   -63,   -63,   390,   -63,   390,   -63,   390,   -63,
     390,   -63,   390,   337,   109,   -63,   106,   -63,   -63,   -63,
     -63,   336,   390,   121,   337,    54,   337,   -63,   341,   -63,
      54,   390
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   129,   130,   -59,    -5,   -63,   -63,   -63,    -1,
     -62,   -63,   -63,   -63,   -63,   -63,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int16 yytable[] =
{
      13,    80,    73,    14,     7,     8,     9,     7,     8,     9,
      21,    22,    93,    95,     1,    10,    15,    30,    10,    34,
       2,   107,    74,    39,    41,    43,    45,    47,    75,    18,
      29,    11,    28,    12,    53,    37,    12,    -7,    60,    33,
      61,   126,   128,   124,    -7,    62,   129,   130,    63,    64,
      -7,    57,    78,    59,     7,     8,     9,     7,     8,     9,
      84,    76,    79,    82,   133,    10,    65,    48,    10,    87,
      88,    90,    74,    51,    94,   137,    52,   139,    75,    56,
     109,    20,   102,    12,    54,    55,    12,    91,    68,     7,
       8,     9,   103,   104,    69,   114,   116,   118,   120,   122,
      10,    19,    71,     7,     8,     9,    72,    74,    86,   131,
     132,   110,   123,    75,    10,     0,   103,   104,    12,   134,
     125,    74,     7,     8,     9,   112,   104,    75,    26,    27,
      28,   136,    12,    10,   138,    16,    17,     0,     0,   141,
      74,   127,     0,     7,     8,     9,    75,     0,     0,     0,
       0,    12,     0,    19,    10,     7,     8,     9,     0,     0,
      38,    74,     7,     8,     9,     0,    10,    75,     0,     0,
      23,     0,    12,    10,    40,     0,     7,     8,     9,    20,
       0,     0,     0,     0,    12,     0,    20,    10,     0,     0,
      42,    12,     7,     8,     9,    24,    25,    26,    27,    28,
      20,     0,     0,    10,    44,    12,     7,     8,     9,     0,
      46,     0,     7,     8,     9,     0,    20,    10,     0,     0,
       0,    12,     0,    10,    81,     0,     7,     8,     9,     0,
      20,     0,    70,     0,     0,    12,    20,    10,     0,     0,
      89,    12,     7,     8,     9,    24,    25,    26,    27,    28,
      20,     0,     0,    10,   113,    12,     7,     8,     9,     0,
     115,     0,     7,     8,     9,     0,    20,    10,     0,     0,
       0,    12,     0,    10,   117,     0,     7,     8,     9,     0,
      20,     0,   111,     0,     0,    12,    20,    10,     0,     0,
     119,    12,     7,     8,     9,    24,    25,    26,    27,    28,
      20,     0,     0,    10,   121,    12,     7,     8,     9,     0,
       0,     0,    60,     0,    61,     0,    20,    10,    60,    62,
      61,    12,    63,    64,     0,    62,     0,     0,    63,    64,
      20,     0,    60,     0,    61,    12,     0,     0,    60,    62,
      61,    83,    63,    64,     0,    62,    35,   108,    63,    64,
     103,   104,     0,     0,   135,     0,     0,     0,    36,   140,
      65,    24,    25,    26,    27,    28,    65,    24,    25,    26,
      27,    28,    24,    25,    26,    27,    28,    96,    97,    98,
      99,   100,     0,    36,     0,     0,    24,    25,    26,    27,
      28,    96,    97,    98,    99,   100,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    36,     0,     0,    24,    25,
      26,    27,    28,    58,     0,     0,    24,    25,    26,    27,
      28,    24,    25,    26,    27,    28
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-63))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,    63,     1,     3,     3,     4,     5,     3,     4,     5,
      11,    12,    74,    75,     7,    14,     0,    18,    14,    20,
      13,    80,    21,    24,    25,    26,    27,    28,    27,    27,
      27,    27,    35,    32,    35,     3,    32,     0,     1,    28,
       3,   103,   104,   102,     7,     8,   105,   106,    11,    12,
      13,    52,     1,    54,     3,     4,     5,     3,     4,     5,
      65,    62,    63,    64,   123,    14,    29,     3,    14,    70,
      71,    72,    21,    28,    75,   134,    16,   136,    27,    16,
      85,    27,     9,    32,    15,    28,    32,     1,     3,     3,
       4,     5,    19,    20,     6,    96,    97,    98,    99,   100,
      14,     1,    15,     3,     4,     5,    15,    21,     3,   110,
     111,    15,     9,    27,    14,    -1,    19,    20,    32,    10,
       1,    21,     3,     4,     5,    28,    20,    27,    33,    34,
      35,    10,    32,    14,   135,     6,     6,    -1,    -1,   140,
      21,     1,    -1,     3,     4,     5,    27,    -1,    -1,    -1,
      -1,    32,    -1,     1,    14,     3,     4,     5,    -1,    -1,
       1,    21,     3,     4,     5,    -1,    14,    27,    -1,    -1,
       6,    -1,    32,    14,     1,    -1,     3,     4,     5,    27,
      -1,    -1,    -1,    -1,    32,    -1,    27,    14,    -1,    -1,
       1,    32,     3,     4,     5,    31,    32,    33,    34,    35,
      27,    -1,    -1,    14,     1,    32,     3,     4,     5,    -1,
       1,    -1,     3,     4,     5,    -1,    27,    14,    -1,    -1,
      -1,    32,    -1,    14,     1,    -1,     3,     4,     5,    -1,
      27,    -1,    18,    -1,    -1,    32,    27,    14,    -1,    -1,
       1,    32,     3,     4,     5,    31,    32,    33,    34,    35,
      27,    -1,    -1,    14,     1,    32,     3,     4,     5,    -1,
       1,    -1,     3,     4,     5,    -1,    27,    14,    -1,    -1,
      -1,    32,    -1,    14,     1,    -1,     3,     4,     5,    -1,
      27,    -1,    18,    -1,    -1,    32,    27,    14,    -1,    -1,
       1,    32,     3,     4,     5,    31,    32,    33,    34,    35,
      27,    -1,    -1,    14,     1,    32,     3,     4,     5,    -1,
      -1,    -1,     1,    -1,     3,    -1,    27,    14,     1,     8,
       3,    32,    11,    12,    -1,     8,    -1,    -1,    11,    12,
      27,    -1,     1,    -1,     3,    32,    -1,    -1,     1,     8,
       3,    30,    11,    12,    -1,     8,    16,    30,    11,    12,
      19,    20,    -1,    -1,    18,    -1,    -1,    -1,    28,    18,
      29,    31,    32,    33,    34,    35,    29,    31,    32,    33,
      34,    35,    31,    32,    33,    34,    35,    22,    23,    24,
      25,    26,    -1,    28,    -1,    -1,    31,    32,    33,    34,
      35,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    28,    -1,    -1,    31,    32,
      33,    34,    35,    28,    -1,    -1,    31,    32,    33,    34,
      35,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    13,    38,    39,    40,    48,     3,     4,     5,
      14,    27,    32,    46,     3,     0,    39,    40,    27,     1,
      27,    46,    46,     6,    31,    32,    33,    34,    35,    27,
      46,    52,    53,    28,    46,    16,    28,     3,     1,    46,
       1,    46,     1,    46,     1,    46,     1,    46,     3,    50,
      51,    28,    16,    46,    15,    28,    16,    46,    28,    46,
       1,     3,     8,    11,    12,    29,    41,    42,     3,     6,
      18,    15,    15,     1,    21,    27,    46,    47,     1,    46,
      47,     1,    46,    30,    42,    49,     3,    46,    46,     1,
      46,     1,    46,    47,    46,    47,    22,    23,    24,    25,
      26,    43,     9,    19,    20,    45,    44,    41,    30,    42,
      15,    18,    28,     1,    46,     1,    46,     1,    46,     1,
      46,     1,    46,     9,    41,     1,    47,     1,    47,    41,
      41,    46,    46,    41,    10,    18,    10,    41,    46,    41,
      18,    46
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1806 of yacc.c  */
#line 75 "src/parser.y"
    { pg = (yyval._pg) = mp<ast_program>((yyvsp[(1) - (2)]._fds), (yyvsp[(2) - (2)]._pc), line_num); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 78 "src/parser.y"
    { pg = (yyval._pg) = mp<ast_program>((yyvsp[(1) - (1)]._fds), mp<ast_syntax_error>("Falta definir la instrucción de plot.", line_num), line_num); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 79 "src/parser.y"
    { pg = (yyval._pg) = mp<ast_program>(mp<list<ptr<ast_fun_def>>>(1, mp<ast_syntax_error>("No se definió ninguna función.", line_num)), (yyvsp[(1) - (1)]._pc), line_num); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 80 "src/parser.y"
    { pg = (yyval._pg) = mp<ast_program>(mp<list<ptr<ast_fun_def>>>(1, mp<ast_syntax_error>("No se definió ninguna función.", line_num)), mp<ast_syntax_error>("Falta definir la instrucción de plot.", line_num), line_num); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 85 "src/parser.y"
    { (yyval._fd) = mp<ast_fun_def>((yyvsp[(2) - (6)]._id), (yyvsp[(4) - (6)]._ids), (yyvsp[(6) - (6)]._bl), line_num); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 89 "src/parser.y"
    { (yyval._fd) = mp<ast_syntax_error>("La definición de la función \'" + *(yyvsp[(2) - (5)]._id) + "\' está incompleta.", line_num); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 95 "src/parser.y"
    { (yyval._pc) = mp<ast_plot_cmd>((yyvsp[(3) - (14)]._ex), (yyvsp[(5) - (14)]._ex), (yyvsp[(8) - (14)]._id), (yyvsp[(10) - (14)]._ex), (yyvsp[(12) - (14)]._ex), (yyvsp[(14) - (14)]._ex), line_num); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 100 "src/parser.y"
    { (yyval._pc) = mp<ast_syntax_error>("En la instrucción plot, se espera un par (fx(...),fy(...)) luego de la palabra \"plot\".", line_num); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 102 "src/parser.y"
    { (yyval._pc) = mp<ast_syntax_error>("En la instrucción plot, falta definir un rango de evaluación.", line_num); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 106 "src/parser.y"
    { (yyval._bl) = mp<ast_block>(mp<list<ptr<ast_stmt>>>(1, (yyvsp[(1) - (1)]._st)), line_num); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 107 "src/parser.y"
    { (yyval._bl) = mp<ast_block>((yyvsp[(2) - (3)]._sts), line_num); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 110 "src/parser.y"
    { (yyval._bl) = mp<ast_syntax_error>("Un bloque de instrucciones no puede ser vacío.", line_num); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 114 "src/parser.y"
    { (yyval._st) = mp<ast_var_assign_stmt>((yyvsp[(1) - (3)]._id), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 115 "src/parser.y"
    { (yyval._st) = mp<ast_if_then_stmt>((yyvsp[(2) - (4)]._pr), (yyvsp[(4) - (4)]._bl), line_num); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 116 "src/parser.y"
    { (yyval._st) = mp<ast_if_then_else_stmt>((yyvsp[(2) - (6)]._pr), (yyvsp[(4) - (6)]._bl), (yyvsp[(6) - (6)]._bl), line_num); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 117 "src/parser.y"
    { (yyval._st) = mp<ast_while_stmt>((yyvsp[(2) - (3)]._pr), (yyvsp[(3) - (3)]._bl), line_num); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 118 "src/parser.y"
    { (yyval._st) = mp<ast_return_stmt>((yyvsp[(2) - (2)]._ex), line_num); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 121 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("Instrucción de asignación inválida.", line_num); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 122 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("La expresión de lado derecho de la asignación es inválida.", line_num); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 123 "src/parser.y"
    { temp = line_num; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 123 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("La guarda de un if debe ser un predicado con valor booleano.", temp); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 124 "src/parser.y"
    { temp = line_num; }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 124 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("La guarda de un while debe ser un predicado con valor booleano.", temp); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 125 "src/parser.y"
    { temp = line_num; }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 125 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("Falta la palabra clave 'then' en la instrucción if.", temp); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 126 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("La guarda del if es inválida.", line_num); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 127 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("La guarda del while es inválida.", line_num); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 128 "src/parser.y"
    { (yyval._st) = mp<ast_syntax_error>("La expresión de retorno es inválida.", line_num); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 132 "src/parser.y"
    { (yyval._ex) = mp<ast_literal_expr>(stofp_t(*(yyvsp[(1) - (1)]._str)), line_num); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 133 "src/parser.y"
    { (yyval._ex) = mp<ast_literal_expr>(stofp_t(*(yyvsp[(1) - (1)]._str)), line_num); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 134 "src/parser.y"
    { (yyval._ex) = mp<ast_literal_expr>(FP_T_PI, line_num); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 135 "src/parser.y"
    { (yyval._ex) = mp<ast_id_expr>((yyvsp[(1) - (1)]._id), line_num); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 136 "src/parser.y"
    { (yyval._ex) = mp<ast_bin_op_expr>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 137 "src/parser.y"
    { (yyval._ex) = mp<ast_bin_op_expr>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 138 "src/parser.y"
    { (yyval._ex) = mp<ast_bin_op_expr>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 139 "src/parser.y"
    { (yyval._ex) = mp<ast_bin_op_expr>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 140 "src/parser.y"
    { (yyval._ex) = mp<ast_uny_op_expr>((yyvsp[(1) - (2)]._int), (yyvsp[(2) - (2)]._ex), line_num); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 141 "src/parser.y"
    { (yyval._ex) = mp<ast_bin_op_expr>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 142 "src/parser.y"
    { (yyval._ex) = mp<ast_fun_call_expr>((yyvsp[(1) - (4)]._id), (yyvsp[(3) - (4)]._exs), line_num); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 143 "src/parser.y"
    { (yyval._ex) = (yyvsp[(2) - (3)]._ex); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 146 "src/parser.y"
    { (yyval._ex) = mp<ast_syntax_error>("Expresión inválida.", line_num); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 147 "src/parser.y"
    { (yyval._ex) = mp<ast_syntax_error>("Expresión inválida.", line_num); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 148 "src/parser.y"
    { (yyval._ex) = mp<ast_syntax_error>("Expresión inválida.", line_num); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 149 "src/parser.y"
    { (yyval._ex) = mp<ast_syntax_error>("Expresión inválida.", line_num); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 150 "src/parser.y"
    { (yyval._ex) = mp<ast_syntax_error>("Expresión inválida.", line_num); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 151 "src/parser.y"
    { (yyval._ex) = mp<ast_syntax_error>("Expresión inválida.", line_num); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 155 "src/parser.y"
    { (yyval._pr) = mp<ast_rel_pred>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 156 "src/parser.y"
    { (yyval._pr) = mp<ast_rel_pred>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 157 "src/parser.y"
    { (yyval._pr) = mp<ast_rel_pred>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 158 "src/parser.y"
    { (yyval._pr) = mp<ast_rel_pred>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 159 "src/parser.y"
    { (yyval._pr) = mp<ast_rel_pred>((yyvsp[(1) - (3)]._ex), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._ex), line_num); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 160 "src/parser.y"
    { (yyval._pr) = mp<ast_bin_l_pred>((yyvsp[(1) - (3)]._pr), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._pr), line_num); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 161 "src/parser.y"
    { (yyval._pr) = mp<ast_bin_l_pred>((yyvsp[(1) - (3)]._pr), (yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)]._pr), line_num); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 162 "src/parser.y"
    { (yyval._pr) = mp<ast_uny_l_pred>((yyvsp[(1) - (2)]._int), (yyvsp[(2) - (2)]._pr), line_num); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 163 "src/parser.y"
    { (yyval._pr) = (yyvsp[(2) - (3)]._pr); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 166 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 167 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 168 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 169 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 170 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 171 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 172 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 173 "src/parser.y"
    { (yyval._pr) = mp<ast_syntax_error>("Predicado inválido", line_num); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 177 "src/parser.y"
    { (yyval._fds) = mp<list<ptr<ast_fun_def>>>(1, (yyvsp[(1) - (1)]._fd)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 178 "src/parser.y"
    { (yyval._fds) = (yyvsp[(1) - (2)]._fds); (yyval._fds)->push_back((yyvsp[(2) - (2)]._fd)); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 182 "src/parser.y"
    { (yyval._sts) = mp<list<ptr<ast_stmt>>>(1, (yyvsp[(1) - (1)]._st)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 183 "src/parser.y"
    { (yyval._sts) = (yyvsp[(1) - (2)]._sts); (yyval._sts)->push_back((yyvsp[(2) - (2)]._st)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 187 "src/parser.y"
    { (yyval._ids) = mp<list<ptr<id>>>(); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 188 "src/parser.y"
    { (yyval._ids) = (yyvsp[(1) - (1)]._ids); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 192 "src/parser.y"
    { (yyval._ids) = mp<list<ptr<id>>>(1, (yyvsp[(1) - (1)]._id)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 193 "src/parser.y"
    { (yyval._ids) = (yyvsp[(1) - (3)]._ids); (yyval._ids)->push_back((yyvsp[(3) - (3)]._id)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 197 "src/parser.y"
    { (yyval._exs) = mp<list<ptr<ast_expr>>>(); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 198 "src/parser.y"
    { (yyval._exs) = (yyvsp[(1) - (1)]._exs); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 202 "src/parser.y"
    { (yyval._exs) = mp<list<ptr<ast_expr>>>(1, (yyvsp[(1) - (1)]._ex)); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 203 "src/parser.y"
    { (yyval._exs) = (yyvsp[(1) - (3)]._exs); (yyval._exs)->push_back((yyvsp[(3) - (3)]._ex)); }
    break;



/* Line 1806 of yacc.c  */
#line 2101 "src/auto/parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 206 "src/parser.y"

