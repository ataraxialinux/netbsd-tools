/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parsedate.y"

/*
**  Originally written by Steven M. Bellovin <smb@research.att.com> while
**  at the University of North Carolina at Chapel Hill.  Later tweaked by
**  a couple of people on Usenet.  Completely overhauled by Rich $alz
**  <rsalz@bbn.com> and Jim Berets <jberets@bbn.com> in August, 1990;
**
**  This grammar has 10 shift/reduce conflicts.
**
**  This code is in the public domain and has no copyright.
*/
/* SUPPRESS 287 on yaccpar_sccsid *//* Unused static variable */
/* SUPPRESS 288 on yyerrlab *//* Label unused */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <bsd.h>
#include <stdlib.h>

/* NOTES on rebuilding parsedate.c (particularly for inclusion in CVS
   releases):

   We don't want to mess with all the portability hassles of alloca.
   In particular, most (all?) versions of bison will use alloca in
   their parser.  If bison works on your system (e.g. it should work
   with gcc), then go ahead and use it, but the more general solution
   is to use byacc instead of bison, which should generate a portable
   parser.  I played with adding "#define alloca dont_use_alloca", to
   give an error if the parser generator uses alloca (and thus detect
   unportable parsedate.c's), but that seems to cause as many problems
   as it solves.  */

#define EPOCH		1970
#define HOUR(x)		((time_t)(x) * 60)
#define SECSPERDAY	(24L * 60L * 60L)


/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    const char	*name;
    int		type;
    time_t	value;
} TABLE;


/*
**  Daylight-savings mode:  on, off, or not yet known.
*/
typedef enum _DSTMODE {
    DSTon, DSToff, DSTmaybe
} DSTMODE;

/*
**  Meridian:  am, pm, or 24-hour style.
*/
typedef enum _MERIDIAN {
    MERam, MERpm, MER24
} MERIDIAN;


struct dateinfo {
	DSTMODE	yyDSTmode;
	time_t	yyDayOrdinal;
	time_t	yyDayNumber;
	int	yyHaveDate;
	int	yyHaveDay;
	int	yyHaveRel;
	int	yyHaveTime;
	int	yyHaveZone;
	time_t	yyTimezone;
	time_t	yyDay;
	time_t	yyHour;
	time_t	yyMinutes;
	time_t	yyMonth;
	time_t	yySeconds;
	time_t	yyYear;
	MERIDIAN	yyMeridian;
	time_t	yyRelMonth;
	time_t	yyRelSeconds;
};

#line 156 "parsedate.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tAGO = 258,
    tDAY = 259,
    tDAYZONE = 260,
    tID = 261,
    tMERIDIAN = 262,
    tMINUTE_UNIT = 263,
    tMONTH = 264,
    tMONTH_UNIT = 265,
    tSEC_UNIT = 266,
    tSNUMBER = 267,
    tUNUMBER = 268,
    tZONE = 269,
    tDST = 270,
    AT_SIGN = 271
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 87 "parsedate.y"

    time_t		Number;
    enum _MERIDIAN	Meridian;

#line 218 "parsedate.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (struct dateinfo *param, const char **yyInput);





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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   57

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  68

#define YYUNDEFTOK  2
#define YYMAXUTOK   271

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    19,     2,    17,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,     2,
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
      15,    16
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   110,   113,   116,   119,   122,   125,
     130,   135,   138,   151,   176,   182,   188,   195,   201,   209,
     220,   224,   229,   235,   239,   243,   249,   253,   264,   270,
     276,   280,   285,   289,   296,   300,   303,   306,   309,   312,
     315,   318,   321,   324,   327,   332,   359,   362
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tAGO", "tDAY", "tDAYZONE", "tID",
  "tMERIDIAN", "tMINUTE_UNIT", "tMONTH", "tMONTH_UNIT", "tSEC_UNIT",
  "tSNUMBER", "tUNUMBER", "tZONE", "tDST", "AT_SIGN", "'.'", "':'", "','",
  "'/'", "$accept", "spec", "item", "cvsstamp", "epochdate", "time",
  "zone", "day", "date", "rel", "relunit", "number", "o_merid", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    46,    58,    44,
      47
};
# endif

#define YYPACT_NINF -17

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-17)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -17,     0,   -17,   -16,   -17,   -17,    -7,   -17,   -17,    30,
      11,    -8,     4,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,    21,   -17,   -17,     7,   -17,   -17,   -17,   -17,   -17,
     -17,   -11,   -17,   -17,    22,    26,    29,    31,   -17,   -17,
     -17,    32,   -17,   -17,   -17,    16,    18,    15,   -17,    33,
     -17,   -17,    34,   -17,    35,    36,    20,   -17,    37,   -17,
      38,   -17,    39,   -17,    41,    40,    42,   -17
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    23,    21,    38,     0,    44,    41,     0,
      45,    20,     0,     3,     9,    10,     4,     5,     7,     6,
       8,    35,    11,    24,    30,    37,    42,    39,    25,    14,
      36,    32,    43,    40,     0,     0,     0,     0,    22,    13,
      34,     0,    29,    33,    28,     0,    46,    26,    31,     0,
      47,    16,     0,    15,     0,     0,    46,    27,     0,    18,
       0,    17,     0,    19,     0,     0,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       2,    42,    43,    23,     3,     4,    24,    38,     5,     6,
       7,     8,     9,    10,    11,    28,    12,    39,    29,    30,
      31,    32,    33,    34,    40,    50,    41,    50,    35,    36,
      51,    37,    59,    49,    44,    54,    52,    60,    25,    45,
      26,    27,    46,    61,    47,    48,    55,    56,    57,     0,
      62,    63,     0,    58,    65,    67,    64,    66
};

static const yytype_int8 yycheck[] =
{
       0,    12,    13,    19,     4,     5,    13,    15,     8,     9,
      10,    11,    12,    13,    14,     4,    16,    13,     7,     8,
       9,    10,    11,    12,     3,     7,    19,     7,    17,    18,
      12,    20,    12,    17,    12,    20,    18,    17,     8,    13,
      10,    11,    13,    56,    13,    13,    13,    13,    13,    -1,
      13,    13,    -1,    17,    13,    13,    17,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,     0,     4,     5,     8,     9,    10,    11,    12,
      13,    14,    16,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    19,    13,     8,    10,    11,     4,     7,
       8,     9,    10,    11,    12,    17,    18,    20,    15,    13,
       3,    19,    12,    13,    12,    13,    13,    13,    13,    17,
       7,    12,    18,    33,    20,    13,    13,    13,    17,    12,
      17,    33,    13,    13,    17,    13,    17,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    21,    22,    22,    23,    23,    23,    23,    23,    23,
      23,    23,    24,    25,    26,    26,    26,    26,    26,    26,
      27,    27,    27,    28,    28,    28,    29,    29,    29,    29,
      29,    29,    29,    29,    30,    30,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    32,    33,    33
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,    11,     2,     2,     4,     4,     6,     6,     7,
       1,     1,     2,     1,     2,     2,     3,     5,     3,     3,
       2,     4,     2,     3,     2,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     1,     0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (param, yyInput, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, param, yyInput); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, struct dateinfo *param, const char **yyInput)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (param);
  YYUSE (yyInput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, struct dateinfo *param, const char **yyInput)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, param, yyInput);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, struct dateinfo *param, const char **yyInput)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , param, yyInput);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, param, yyInput); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct dateinfo *param, const char **yyInput)
{
  YYUSE (yyvaluep);
  YYUSE (param);
  YYUSE (yyInput);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct dateinfo *param, const char **yyInput)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      //yychar = yylex (&yylval, yyInput);
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4:
#line 110 "parsedate.y"
    {
	    param->yyHaveTime++;
	}
#line 1357 "parsedate.tab.c"
    break;

  case 5:
#line 113 "parsedate.y"
    {
	    param->yyHaveZone++;
	}
#line 1365 "parsedate.tab.c"
    break;

  case 6:
#line 116 "parsedate.y"
    {
	    param->yyHaveDate++;
	}
#line 1373 "parsedate.tab.c"
    break;

  case 7:
#line 119 "parsedate.y"
    {
	    param->yyHaveDay++;
	}
#line 1381 "parsedate.tab.c"
    break;

  case 8:
#line 122 "parsedate.y"
    {
	    param->yyHaveRel++;
	}
#line 1389 "parsedate.tab.c"
    break;

  case 9:
#line 125 "parsedate.y"
    {
	    param->yyHaveTime++;
	    param->yyHaveDate++;
	    param->yyHaveZone++;
	}
#line 1399 "parsedate.tab.c"
    break;

  case 10:
#line 130 "parsedate.y"
    {
	    param->yyHaveTime++;
	    param->yyHaveDate++;
	    param->yyHaveZone++;
	}
#line 1409 "parsedate.tab.c"
    break;

  case 12:
#line 138 "parsedate.y"
    {
	    param->yyYear = (yyvsp[-10].Number);
	    if (param->yyYear < 100) param->yyYear += 1900;
	    param->yyMonth = (yyvsp[-8].Number);
	    param->yyDay = (yyvsp[-6].Number);
	    param->yyHour = (yyvsp[-4].Number);
	    param->yyMinutes = (yyvsp[-2].Number);
	    param->yySeconds = (yyvsp[0].Number);
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = 0;
	}
#line 1425 "parsedate.tab.c"
    break;

  case 13:
#line 151 "parsedate.y"
    {
            time_t    when = (yyvsp[0].Number);
            struct tm tmbuf;
            if (gmtime_r(&when, &tmbuf) != NULL) {
		param->yyYear = tmbuf.tm_year + 1900;
		param->yyMonth = tmbuf.tm_mon + 1;
		param->yyDay = tmbuf.tm_mday;

		param->yyHour = tmbuf.tm_hour;
		param->yyMinutes = tmbuf.tm_min;
		param->yySeconds = tmbuf.tm_sec;
	    } else {
		param->yyYear = EPOCH;
		param->yyMonth = 1;
		param->yyDay = 1;

		param->yyHour = 0;
		param->yyMinutes = 0;
		param->yySeconds = 0;
	    }
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = 0;
	}
#line 1453 "parsedate.tab.c"
    break;

  case 14:
#line 176 "parsedate.y"
    {
	    param->yyHour = (yyvsp[-1].Number);
	    param->yyMinutes = 0;
	    param->yySeconds = 0;
	    param->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1464 "parsedate.tab.c"
    break;

  case 15:
#line 182 "parsedate.y"
    {
	    param->yyHour = (yyvsp[-3].Number);
	    param->yyMinutes = (yyvsp[-1].Number);
	    param->yySeconds = 0;
	    param->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1475 "parsedate.tab.c"
    break;

  case 16:
#line 188 "parsedate.y"
    {
	    param->yyHour = (yyvsp[-3].Number);
	    param->yyMinutes = (yyvsp[-1].Number);
	    param->yyMeridian = MER24;
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = - ((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
	}
#line 1487 "parsedate.tab.c"
    break;

  case 17:
#line 195 "parsedate.y"
    {
	    param->yyHour = (yyvsp[-5].Number);
	    param->yyMinutes = (yyvsp[-3].Number);
	    param->yySeconds = (yyvsp[-1].Number);
	    param->yyMeridian = (yyvsp[0].Meridian);
	}
#line 1498 "parsedate.tab.c"
    break;

  case 18:
#line 201 "parsedate.y"
    {
	    param->yyHour = (yyvsp[-5].Number);
	    param->yyMinutes = (yyvsp[-3].Number);
	    param->yySeconds = (yyvsp[-1].Number);
	    param->yyMeridian = MER24;
	    param->yyDSTmode = DSToff;
	    param->yyTimezone = - ((yyvsp[0].Number) % 100 + ((yyvsp[0].Number) / 100) * 60);
	}
#line 1511 "parsedate.tab.c"
    break;

  case 19:
#line 209 "parsedate.y"
    {
	    param->yyHour = (yyvsp[-6].Number);
	    param->yyMinutes = (yyvsp[-4].Number);
	    param->yySeconds = (yyvsp[-2].Number);
	    param->yyMeridian = MER24;
	    param->yyDSTmode = DSToff;
/* XXX: Do nothing with millis */
/*	    param->yyTimezone = ($7 % 100 + ($7 / 100) * 60); */
	}
#line 1525 "parsedate.tab.c"
    break;

  case 20:
#line 220 "parsedate.y"
    {
	    param->yyTimezone = (yyvsp[0].Number);
	    param->yyDSTmode = DSToff;
	}
#line 1534 "parsedate.tab.c"
    break;

  case 21:
#line 224 "parsedate.y"
    {
	    param->yyTimezone = (yyvsp[0].Number);
	    param->yyDSTmode = DSTon;
	}
#line 1543 "parsedate.tab.c"
    break;

  case 22:
#line 229 "parsedate.y"
    {
	    param->yyTimezone = (yyvsp[-1].Number);
	    param->yyDSTmode = DSTon;
	}
#line 1552 "parsedate.tab.c"
    break;

  case 23:
#line 235 "parsedate.y"
    {
	    param->yyDayOrdinal = 1;
	    param->yyDayNumber = (yyvsp[0].Number);
	}
#line 1561 "parsedate.tab.c"
    break;

  case 24:
#line 239 "parsedate.y"
    {
	    param->yyDayOrdinal = 1;
	    param->yyDayNumber = (yyvsp[-1].Number);
	}
#line 1570 "parsedate.tab.c"
    break;

  case 25:
#line 243 "parsedate.y"
    {
	    param->yyDayOrdinal = (yyvsp[-1].Number);
	    param->yyDayNumber = (yyvsp[0].Number);
	}
#line 1579 "parsedate.tab.c"
    break;

  case 26:
#line 249 "parsedate.y"
    {
	    param->yyMonth = (yyvsp[-2].Number);
	    param->yyDay = (yyvsp[0].Number);
	}
#line 1588 "parsedate.tab.c"
    break;

  case 27:
#line 253 "parsedate.y"
    {
	    if ((yyvsp[-4].Number) >= 100) {
		param->yyYear = (yyvsp[-4].Number);
		param->yyMonth = (yyvsp[-2].Number);
		param->yyDay = (yyvsp[0].Number);
	    } else {
		param->yyMonth = (yyvsp[-4].Number);
		param->yyDay = (yyvsp[-2].Number);
		param->yyYear = (yyvsp[0].Number);
	    }
	}
#line 1604 "parsedate.tab.c"
    break;

  case 28:
#line 264 "parsedate.y"
    {
	    /* ISO 8601 format.  yyyy-mm-dd.  */
	    param->yyYear = (yyvsp[-2].Number);
	    param->yyMonth = -(yyvsp[-1].Number);
	    param->yyDay = -(yyvsp[0].Number);
	}
#line 1615 "parsedate.tab.c"
    break;

  case 29:
#line 270 "parsedate.y"
    {
	    /* e.g. 17-JUN-1992.  */
	    param->yyDay = (yyvsp[-2].Number);
	    param->yyMonth = (yyvsp[-1].Number);
	    param->yyYear = -(yyvsp[0].Number);
	}
#line 1626 "parsedate.tab.c"
    break;

  case 30:
#line 276 "parsedate.y"
    {
	    param->yyMonth = (yyvsp[-1].Number);
	    param->yyDay = (yyvsp[0].Number);
	}
#line 1635 "parsedate.tab.c"
    break;

  case 31:
#line 280 "parsedate.y"
    {
	    param->yyMonth = (yyvsp[-3].Number);
	    param->yyDay = (yyvsp[-2].Number);
	    param->yyYear = (yyvsp[0].Number);
	}
#line 1645 "parsedate.tab.c"
    break;

  case 32:
#line 285 "parsedate.y"
    {
	    param->yyMonth = (yyvsp[0].Number);
	    param->yyDay = (yyvsp[-1].Number);
	}
#line 1654 "parsedate.tab.c"
    break;

  case 33:
#line 289 "parsedate.y"
    {
	    param->yyMonth = (yyvsp[-1].Number);
	    param->yyDay = (yyvsp[-2].Number);
	    param->yyYear = (yyvsp[0].Number);
	}
#line 1664 "parsedate.tab.c"
    break;

  case 34:
#line 296 "parsedate.y"
    {
	    param->yyRelSeconds = -param->yyRelSeconds;
	    param->yyRelMonth = -param->yyRelMonth;
	}
#line 1673 "parsedate.tab.c"
    break;

  case 36:
#line 303 "parsedate.y"
    {
	    param->yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number) * 60L;
	}
#line 1681 "parsedate.tab.c"
    break;

  case 37:
#line 306 "parsedate.y"
    {
	    param->yyRelSeconds += (yyvsp[-1].Number) * (yyvsp[0].Number) * 60L;
	}
#line 1689 "parsedate.tab.c"
    break;

  case 38:
#line 309 "parsedate.y"
    {
	    param->yyRelSeconds += (yyvsp[0].Number) * 60L;
	}
#line 1697 "parsedate.tab.c"
    break;

  case 39:
#line 312 "parsedate.y"
    {
	    param->yyRelSeconds += (yyvsp[-1].Number);
	}
#line 1705 "parsedate.tab.c"
    break;

  case 40:
#line 315 "parsedate.y"
    {
	    param->yyRelSeconds += (yyvsp[-1].Number);
	}
#line 1713 "parsedate.tab.c"
    break;

  case 41:
#line 318 "parsedate.y"
    {
	    param->yyRelSeconds++;
	}
#line 1721 "parsedate.tab.c"
    break;

  case 42:
#line 321 "parsedate.y"
    {
	    param->yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1729 "parsedate.tab.c"
    break;

  case 43:
#line 324 "parsedate.y"
    {
	    param->yyRelMonth += (yyvsp[-1].Number) * (yyvsp[0].Number);
	}
#line 1737 "parsedate.tab.c"
    break;

  case 44:
#line 327 "parsedate.y"
    {
	    param->yyRelMonth += (yyvsp[0].Number);
	}
#line 1745 "parsedate.tab.c"
    break;

  case 45:
#line 332 "parsedate.y"
    {
	    if (param->yyHaveTime && param->yyHaveDate && !param->yyHaveRel)
		param->yyYear = (yyvsp[0].Number);
	    else {
		if((yyvsp[0].Number)>10000) {
		    param->yyHaveDate++;
		    param->yyDay= ((yyvsp[0].Number))%100;
		    param->yyMonth= ((yyvsp[0].Number)/100)%100;
		    param->yyYear = (yyvsp[0].Number)/10000;
		}
		else {
		    param->yyHaveTime++;
		    if ((yyvsp[0].Number) < 100) {
			param->yyHour = (yyvsp[0].Number);
			param->yyMinutes = 0;
		    }
		    else {
		    	param->yyHour = (yyvsp[0].Number) / 100;
		    	param->yyMinutes = (yyvsp[0].Number) % 100;
		    }
		    param->yySeconds = 0;
		    param->yyMeridian = MER24;
	        }
	    }
	}
#line 1775 "parsedate.tab.c"
    break;

  case 46:
#line 359 "parsedate.y"
    {
	    (yyval.Meridian) = MER24;
	}
#line 1783 "parsedate.tab.c"
    break;

  case 47:
#line 362 "parsedate.y"
    {
	    (yyval.Meridian) = (yyvsp[0].Meridian);
	}
#line 1791 "parsedate.tab.c"
    break;


#line 1795 "parsedate.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      //yyerror (param, yyInput, YY_("syntax error"));
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
        yyerror (param, yyInput, yymsgp);
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
                      yytoken, &yylval, param, yyInput);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
                  yystos[yystate], yyvsp, param, yyInput);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  //yyerror (param, yyInput, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, param, yyInput);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, param, yyInput);
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
  return yyresult;
}
#line 367 "parsedate.y"


/* Month and day table. */
static const TABLE MonthDayTable[] = {
    { "january",	tMONTH,  1 },
    { "february",	tMONTH,  2 },
    { "march",		tMONTH,  3 },
    { "april",		tMONTH,  4 },
    { "may",		tMONTH,  5 },
    { "june",		tMONTH,  6 },
    { "july",		tMONTH,  7 },
    { "august",		tMONTH,  8 },
    { "september",	tMONTH,  9 },
    { "sept",		tMONTH,  9 },
    { "october",	tMONTH, 10 },
    { "november",	tMONTH, 11 },
    { "december",	tMONTH, 12 },
    { "sunday",		tDAY, 0 },
    { "monday",		tDAY, 1 },
    { "tuesday",	tDAY, 2 },
    { "tues",		tDAY, 2 },
    { "wednesday",	tDAY, 3 },
    { "wednes",		tDAY, 3 },
    { "thursday",	tDAY, 4 },
    { "thur",		tDAY, 4 },
    { "thurs",		tDAY, 4 },
    { "friday",		tDAY, 5 },
    { "saturday",	tDAY, 6 },
    { NULL,		0,    0 }
};

/* Time units table. */
static const TABLE UnitsTable[] = {
    { "year",		tMONTH_UNIT,	12 },
    { "month",		tMONTH_UNIT,	1 },
    { "fortnight",	tMINUTE_UNIT,	14 * 24 * 60 },
    { "week",		tMINUTE_UNIT,	7 * 24 * 60 },
    { "day",		tMINUTE_UNIT,	1 * 24 * 60 },
    { "hour",		tMINUTE_UNIT,	60 },
    { "minute",		tMINUTE_UNIT,	1 },
    { "min",		tMINUTE_UNIT,	1 },
    { "second",		tSEC_UNIT,	1 },
    { "sec",		tSEC_UNIT,	1 },
    { NULL,		0,		0 }
};

/* Assorted relative-time words. */
static const TABLE OtherTable[] = {
    { "tomorrow",	tMINUTE_UNIT,	1 * 24 * 60 },
    { "yesterday",	tMINUTE_UNIT,	-1 * 24 * 60 },
    { "today",		tMINUTE_UNIT,	0 },
    { "now",		tMINUTE_UNIT,	0 },
    { "last",		tUNUMBER,	-1 },
    { "this",		tMINUTE_UNIT,	0 },
    { "next",		tUNUMBER,	2 },
    { "first",		tUNUMBER,	1 },
    { "one",		tUNUMBER,	1 },
/*  { "second",		tUNUMBER,	2 }, */
    { "two",		tUNUMBER,	2 },
    { "third",		tUNUMBER,	3 },
    { "three",		tUNUMBER,	3 },
    { "fourth",		tUNUMBER,	4 },
    { "four",		tUNUMBER,	4 },
    { "fifth",		tUNUMBER,	5 },
    { "five",		tUNUMBER,	5 },
    { "sixth",		tUNUMBER,	6 },
    { "six",		tUNUMBER,	6 },
    { "seventh",	tUNUMBER,	7 },
    { "seven",		tUNUMBER,	7 },
    { "eighth",		tUNUMBER,	8 },
    { "eight",		tUNUMBER,	8 },
    { "ninth",		tUNUMBER,	9 },
    { "nine",		tUNUMBER,	9 },
    { "tenth",		tUNUMBER,	10 },
    { "ten",		tUNUMBER,	10 },
    { "eleventh",	tUNUMBER,	11 },
    { "eleven",		tUNUMBER,	11 },
    { "twelfth",	tUNUMBER,	12 },
    { "twelve",		tUNUMBER,	12 },
    { "ago",		tAGO,	1 },
    { NULL,		0,	0 }
};

/* The timezone table. */
/* Some of these are commented out because a time_t can't store a float. */
static const TABLE TimezoneTable[] = {
    { "gmt",	tZONE,     HOUR( 0) },	/* Greenwich Mean */
    { "ut",	tZONE,     HOUR( 0) },	/* Universal (Coordinated) */
    { "utc",	tZONE,     HOUR( 0) },
    { "wet",	tZONE,     HOUR( 0) },	/* Western European */
    { "bst",	tDAYZONE,  HOUR( 0) },	/* British Summer */
    { "wat",	tZONE,     HOUR( 1) },	/* West Africa */
    { "at",	tZONE,     HOUR( 2) },	/* Azores */
#if	0
    /* For completeness.  BST is also British Summer, and GST is
     * also Guam Standard. */
    { "bst",	tZONE,     HOUR( 3) },	/* Brazil Standard */
    { "gst",	tZONE,     HOUR( 3) },	/* Greenland Standard */
#endif
#if 0
    { "nft",	tZONE,     HOUR(3.5) },	/* Newfoundland */
    { "nst",	tZONE,     HOUR(3.5) },	/* Newfoundland Standard */
    { "ndt",	tDAYZONE,  HOUR(3.5) },	/* Newfoundland Daylight */
#endif
    { "ast",	tZONE,     HOUR( 4) },	/* Atlantic Standard */
    { "adt",	tDAYZONE,  HOUR( 4) },	/* Atlantic Daylight */
    { "est",	tZONE,     HOUR( 5) },	/* Eastern Standard */
    { "edt",	tDAYZONE,  HOUR( 5) },	/* Eastern Daylight */
    { "cst",	tZONE,     HOUR( 6) },	/* Central Standard */
    { "cdt",	tDAYZONE,  HOUR( 6) },	/* Central Daylight */
    { "mst",	tZONE,     HOUR( 7) },	/* Mountain Standard */
    { "mdt",	tDAYZONE,  HOUR( 7) },	/* Mountain Daylight */
    { "pst",	tZONE,     HOUR( 8) },	/* Pacific Standard */
    { "pdt",	tDAYZONE,  HOUR( 8) },	/* Pacific Daylight */
    { "yst",	tZONE,     HOUR( 9) },	/* Yukon Standard */
    { "ydt",	tDAYZONE,  HOUR( 9) },	/* Yukon Daylight */
    { "hst",	tZONE,     HOUR(10) },	/* Hawaii Standard */
    { "hdt",	tDAYZONE,  HOUR(10) },	/* Hawaii Daylight */
    { "cat",	tZONE,     HOUR(10) },	/* Central Alaska */
    { "ahst",	tZONE,     HOUR(10) },	/* Alaska-Hawaii Standard */
    { "nt",	tZONE,     HOUR(11) },	/* Nome */
    { "idlw",	tZONE,     HOUR(12) },	/* International Date Line West */
    { "cet",	tZONE,     -HOUR(1) },	/* Central European */
    { "met",	tZONE,     -HOUR(1) },	/* Middle European */
    { "mewt",	tZONE,     -HOUR(1) },	/* Middle European Winter */
    { "mest",	tDAYZONE,  -HOUR(1) },	/* Middle European Summer */
    { "swt",	tZONE,     -HOUR(1) },	/* Swedish Winter */
    { "sst",	tDAYZONE,  -HOUR(1) },	/* Swedish Summer */
    { "fwt",	tZONE,     -HOUR(1) },	/* French Winter */
    { "fst",	tDAYZONE,  -HOUR(1) },	/* French Summer */
    { "eet",	tZONE,     -HOUR(2) },	/* Eastern Europe, USSR Zone 1 */
    { "bt",	tZONE,     -HOUR(3) },	/* Baghdad, USSR Zone 2 */
#if 0
    { "it",	tZONE,     -HOUR(3.5) },/* Iran */
#endif
    { "zp4",	tZONE,     -HOUR(4) },	/* USSR Zone 3 */
    { "zp5",	tZONE,     -HOUR(5) },	/* USSR Zone 4 */
#if 0
    { "ist",	tZONE,     -HOUR(5.5) },/* Indian Standard */
#endif
    { "zp6",	tZONE,     -HOUR(6) },	/* USSR Zone 5 */
#if	0
    /* For completeness.  NST is also Newfoundland Stanard, and SST is
     * also Swedish Summer. */
    { "nst",	tZONE,     -HOUR(6.5) },/* North Sumatra */
    { "sst",	tZONE,     -HOUR(7) },	/* South Sumatra, USSR Zone 6 */
#endif	/* 0 */
    { "wast",	tZONE,     -HOUR(7) },	/* West Australian Standard */
    { "wadt",	tDAYZONE,  -HOUR(7) },	/* West Australian Daylight */
#if 0
    { "jt",	tZONE,     -HOUR(7.5) },/* Java (3pm in Cronusland!) */
#endif
    { "cct",	tZONE,     -HOUR(8) },	/* China Coast, USSR Zone 7 */
    { "jst",	tZONE,     -HOUR(9) },	/* Japan Standard, USSR Zone 8 */
#if 0
    { "cast",	tZONE,     -HOUR(9.5) },/* Central Australian Standard */
    { "cadt",	tDAYZONE,  -HOUR(9.5) },/* Central Australian Daylight */
#endif
    { "east",	tZONE,     -HOUR(10) },	/* Eastern Australian Standard */
    { "eadt",	tDAYZONE,  -HOUR(10) },	/* Eastern Australian Daylight */
    { "gst",	tZONE,     -HOUR(10) },	/* Guam Standard, USSR Zone 9 */
    { "nzt",	tZONE,     -HOUR(12) },	/* New Zealand */
    { "nzst",	tZONE,     -HOUR(12) },	/* New Zealand Standard */
    { "nzdt",	tDAYZONE,  -HOUR(12) },	/* New Zealand Daylight */
    { "idle",	tZONE,     -HOUR(12) },	/* International Date Line East */
    {  NULL,	0,	    0 }
};

/* Military timezone table. */
static const TABLE MilitaryTable[] = {
    { "a",	tZONE,	HOUR(  1) },
    { "b",	tZONE,	HOUR(  2) },
    { "c",	tZONE,	HOUR(  3) },
    { "d",	tZONE,	HOUR(  4) },
    { "e",	tZONE,	HOUR(  5) },
    { "f",	tZONE,	HOUR(  6) },
    { "g",	tZONE,	HOUR(  7) },
    { "h",	tZONE,	HOUR(  8) },
    { "i",	tZONE,	HOUR(  9) },
    { "k",	tZONE,	HOUR( 10) },
    { "l",	tZONE,	HOUR( 11) },
    { "m",	tZONE,	HOUR( 12) },
    { "n",	tZONE,	HOUR(- 1) },
    { "o",	tZONE,	HOUR(- 2) },
    { "p",	tZONE,	HOUR(- 3) },
    { "q",	tZONE,	HOUR(- 4) },
    { "r",	tZONE,	HOUR(- 5) },
    { "s",	tZONE,	HOUR(- 6) },
    { "t",	tZONE,	HOUR(- 7) },
    { "u",	tZONE,	HOUR(- 8) },
    { "v",	tZONE,	HOUR(- 9) },
    { "w",	tZONE,	HOUR(-10) },
    { "x",	tZONE,	HOUR(-11) },
    { "y",	tZONE,	HOUR(-12) },
    { "z",	tZONE,	HOUR(  0) },
    { NULL,	0,	0 }
};




/* ARGSUSED */
static int
yyerror(struct dateinfo *param, const char **inp, const char *s)
{
  return 0;
}


/* Year is either
   * A negative number, which means to use its absolute value (why?)
   * A number from 0 to 99, which means a year from 1900 to 1999, or
   * The actual year (>=100).  */
static time_t
Convert(
    time_t	Month,		/* month of year [1-12] */
    time_t	Day,		/* day of month [1-31] */
    time_t	Year,		/* year; see above comment */
    time_t	Hours,		/* Hour of day [0-24] */
    time_t	Minutes,	/* Minute of hour [0-59] */
    time_t	Seconds,	/* Second of minute [0-60] */
    time_t	Timezone,	/* Timezone as seconds west of UTC */
    MERIDIAN	Meridian,	/* Hours are am/pm/24 hour clock */
    DSTMODE	DSTmode		/* DST on/off/maybe */
)
{
    struct tm tm = {.tm_sec = 0};
    time_t result;

    /* XXX Y2K */
    if (Year < 0)
	Year = -Year;
    if (Year < 70)
	Year += 2000;
    else if (Year < 100)
	Year += 1900;

    tm.tm_sec = Seconds;
    tm.tm_min = Minutes;
    tm.tm_hour = Hours + (Meridian == MERpm ? 12 : 0);
    tm.tm_mday = Day;
    tm.tm_mon = Month - 1;
    tm.tm_year = Year - 1900;
    switch (DSTmode) {
    case DSTon:  tm.tm_isdst = 1; break;
    case DSToff: tm.tm_isdst = 0; break;
    default:     tm.tm_isdst = -1; break;
    }

#if !defined(__linux__)
    /* We rely on mktime_z(NULL, ...) working in UTC, not in local time. */
    result = mktime_z(NULL, &tm);
#else
    result = mktime(&tm);
    result += timezone;
#endif
    result -= Timezone;
    return result;
}


static time_t
DSTcorrect(
    time_t	Start,
    time_t	Future
)
{
    time_t	StartDay;
    time_t	FutureDay;
    struct tm  *tm;

    if ((tm = localtime(&Start)) == NULL)
	return -1;
    StartDay = (tm->tm_hour + 1) % 24;

    if ((tm = localtime(&Future)) == NULL)
	return -1;
    FutureDay = (tm->tm_hour + 1) % 24;

    return (Future - Start) + (StartDay - FutureDay) * 60L * 60L;
}


static time_t
RelativeDate(
    time_t	Start,
    time_t	DayOrdinal,
    time_t	DayNumber
)
{
    struct tm	*tm;
    time_t	now;

    now = Start;
    tm = localtime(&now);
    now += SECSPERDAY * ((DayNumber - tm->tm_wday + 7) % 7);
    now += 7 * SECSPERDAY * (DayOrdinal <= 0 ? DayOrdinal : DayOrdinal - 1);
    return DSTcorrect(Start, now);
}


static time_t
RelativeMonth(
    time_t	Start,
    time_t	RelMonth,
    time_t	Timezone
)
{
    struct tm	*tm;
    time_t	Month;
    time_t	Year;

    if (RelMonth == 0)
	return 0;
    tm = localtime(&Start);
    if (tm == NULL)
	return -1;
    Month = 12 * (tm->tm_year + 1900) + tm->tm_mon + RelMonth;
    Year = Month / 12;
    Month = Month % 12 + 1;
    return DSTcorrect(Start,
	    Convert(Month, (time_t)tm->tm_mday, Year,
		(time_t)tm->tm_hour, (time_t)tm->tm_min, (time_t)tm->tm_sec,
		Timezone, MER24, DSTmaybe));
}


static int
LookupWord(YYSTYPE *yylval, char *buff)
{
    register char	*p;
    register char	*q;
    register const TABLE	*tp;
    int			i;
    int			abbrev;

    /* Make it lowercase. */
    for (p = buff; *p; p++)
	if (isupper((unsigned char)*p))
	    *p = tolower((unsigned char)*p);

    if (strcmp(buff, "am") == 0 || strcmp(buff, "a.m.") == 0) {
	yylval->Meridian = MERam;
	return tMERIDIAN;
    }
    if (strcmp(buff, "pm") == 0 || strcmp(buff, "p.m.") == 0) {
	yylval->Meridian = MERpm;
	return tMERIDIAN;
    }

    /* See if we have an abbreviation for a month. */
    if (strlen(buff) == 3)
	abbrev = 1;
    else if (strlen(buff) == 4 && buff[3] == '.') {
	abbrev = 1;
	buff[3] = '\0';
    }
    else
	abbrev = 0;

    for (tp = MonthDayTable; tp->name; tp++) {
	if (abbrev) {
	    if (strncmp(buff, tp->name, 3) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
	}
	else if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}
    }

    for (tp = TimezoneTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    if (strcmp(buff, "dst") == 0) 
	return tDST;

    for (tp = UnitsTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    /* Strip off any plural and try the units table again. */
    i = strlen(buff) - 1;
    if (buff[i] == 's') {
	buff[i] = '\0';
	for (tp = UnitsTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
	buff[i] = 's';		/* Put back for "this" in OtherTable. */
    }

    for (tp = OtherTable; tp->name; tp++)
	if (strcmp(buff, tp->name) == 0) {
	    yylval->Number = tp->value;
	    return tp->type;
	}

    /* Military timezones. */
    if (buff[1] == '\0' && isalpha((unsigned char)*buff)) {
	for (tp = MilitaryTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }
    }

    /* Drop out any periods and try the timezone table again. */
    for (i = 0, p = q = buff; *q; q++)
	if (*q != '.')
	    *p++ = *q;
	else
	    i++;
    *p = '\0';
    if (i)
	for (tp = TimezoneTable; tp->name; tp++)
	    if (strcmp(buff, tp->name) == 0) {
		yylval->Number = tp->value;
		return tp->type;
	    }

    return tID;
}


static int
yylex(YYSTYPE *yylval, const char **yyInput)
{
    register char	c;
    register char	*p;
    char		buff[20];
    int			Count;
    int			sign;
    const char		*inp = *yyInput;

    for ( ; ; ) {
	while (isspace((unsigned char)*inp))
	    inp++;

	if (isdigit((unsigned char)(c = *inp)) || c == '-' || c == '+') {
	    if (c == '-' || c == '+') {
		sign = c == '-' ? -1 : 1;
		if (!isdigit((unsigned char)*++inp))
		    /* skip the '-' sign */
		    continue;
	    }
	    else
		sign = 0;
	    for (yylval->Number = 0; isdigit((unsigned char)(c = *inp++)); )
		yylval->Number = 10 * yylval->Number + c - '0';
	    if (sign < 0)
		yylval->Number = -yylval->Number;
	    *yyInput = --inp;
	    return sign ? tSNUMBER : tUNUMBER;
	}
	if (isalpha((unsigned char)c)) {
	    for (p = buff; isalpha((unsigned char)(c = *inp++)) || c == '.'; )
		if (p < &buff[sizeof buff - 1])
		    *p++ = c;
	    *p = '\0';
	    *yyInput = --inp;
	    return LookupWord(yylval, buff);
	}
	if (c == '@') {
	    *yyInput = ++inp;
	    return AT_SIGN;
	}
	if (c != '(') {
	    *yyInput = ++inp;
	    return c;
	}
	Count = 0;
	do {
	    c = *inp++;
	    if (c == '\0')
		return c;
	    if (c == '(')
		Count++;
	    else if (c == ')')
		Count--;
	} while (Count > 0);
    }
}

#define TM_YEAR_ORIGIN 1900

/* Yield A - B, measured in seconds.  */
static time_t
difftm (struct tm *a, struct tm *b)
{
  int ay = a->tm_year + (TM_YEAR_ORIGIN - 1);
  int by = b->tm_year + (TM_YEAR_ORIGIN - 1);
  int days = (
	      /* difference in day of year */
	      a->tm_yday - b->tm_yday
	      /* + intervening leap days */
	      +  ((ay >> 2) - (by >> 2))
	      -  (ay/100 - by/100)
	      +  ((ay/100 >> 2) - (by/100 >> 2))
	      /* + difference in years * 365 */
	      +  (long)(ay-by) * 365
	      );
  return ((time_t)60*(60*(24*days + (a->tm_hour - b->tm_hour))
	      + (a->tm_min - b->tm_min))
	  + (a->tm_sec - b->tm_sec));
}

time_t
parsedate(const char *p, const time_t *now, const int *zone)
{
    struct tm gmt, local, *gmt_ptr, *tm;
    time_t		nowt;
    int			zonet;
    time_t		Start;
    time_t		tod, rm;
    struct dateinfo	param;

    if (now == NULL || zone == NULL) {
        now = &nowt;
	zone = &zonet;
	(void)time(&nowt);

	gmt_ptr = gmtime_r(now, &gmt);
	if ((tm = localtime_r(now, &local)) == NULL)
	    return -1;

	if (gmt_ptr != NULL)
	    zonet = difftm(&gmt, &local) / 60;
	else
	    /* We are on a system like VMS, where the system clock is
	       in local time and the system has no concept of timezones.
	       Hopefully we can fake this out (for the case in which the
	       user specifies no timezone) by just saying the timezone
	       is zero.  */
	    zonet = 0;

	if (local.tm_isdst)
	    zonet += 60;
    } else {
	if ((tm = localtime_r(now, &local)) == NULL)
	    return -1;
    }
    param.yyYear = tm->tm_year + 1900;
    param.yyMonth = tm->tm_mon + 1;
    param.yyDay = tm->tm_mday;
    param.yyTimezone = *zone;
    param.yyDSTmode = DSTmaybe;
    param.yyHour = 0;
    param.yyMinutes = 0;
    param.yySeconds = 0;
    param.yyMeridian = MER24;
    param.yyRelSeconds = 0;
    param.yyRelMonth = 0;
    param.yyHaveDate = 0;
    param.yyHaveDay = 0;
    param.yyHaveRel = 0;
    param.yyHaveTime = 0;
    param.yyHaveZone = 0;

    if (yyparse(&param, &p) || param.yyHaveTime > 1 || param.yyHaveZone > 1 ||
	param.yyHaveDate > 1 || param.yyHaveDay > 1)
	return -1;

    if (param.yyHaveDate || param.yyHaveTime || param.yyHaveDay) {
	Start = Convert(param.yyMonth, param.yyDay, param.yyYear, param.yyHour,
	    param.yyMinutes, param.yySeconds, param.yyTimezone,
	    param.yyMeridian, param.yyDSTmode);
	if (Start == -1)
	    return -1;
    }
    else {
	Start = *now;
	if (!param.yyHaveRel)
	    Start -= ((tm->tm_hour * 60L + tm->tm_min) * 60L) + tm->tm_sec;
    }

    Start += param.yyRelSeconds;
    rm = RelativeMonth(Start, param.yyRelMonth, param.yyTimezone);
    if (rm == -1)
	return -1;
    Start += rm;

    if (param.yyHaveDay && !param.yyHaveDate) {
	tod = RelativeDate(Start, param.yyDayOrdinal, param.yyDayNumber);
	Start += tod;
    }

    return Start;
}


#if	defined(TEST)

/* ARGSUSED */
int
main(ac, av)
    int		ac;
    char	*av[];
{
    char	buff[128];
    time_t	d;

    (void)printf("Enter date, or blank line to exit.\n\t> ");
    (void)fflush(stdout);
    while (gets(buff) && buff[0]) {
	d = parsedate(buff, NULL, NULL);
	if (d == -1)
	    (void)printf("Bad format - couldn't convert.\n");
	else
	    (void)printf("%s", ctime(&d));
	(void)printf("\t> ");
	(void)fflush(stdout);
    }
    exit(0);
    /* NOTREACHED */
}
#endif	/* defined(TEST) */
