/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include "node.h"
    NBlock *programBlock; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %sn", s); }

#line 79 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TIDENTIFIER = 3,                /* TIDENTIFIER  */
  YYSYMBOL_TFLOAT = 4,                     /* TFLOAT  */
  YYSYMBOL_TINTEGER = 5,                   /* TINTEGER  */
  YYSYMBOL_TSTRING = 6,                    /* TSTRING  */
  YYSYMBOL_TTYPE_STRING = 7,               /* TTYPE_STRING  */
  YYSYMBOL_TTYPE_INT = 8,                  /* TTYPE_INT  */
  YYSYMBOL_TTYPE_FLOAT = 9,                /* TTYPE_FLOAT  */
  YYSYMBOL_TTYPE_VOID = 10,                /* TTYPE_VOID  */
  YYSYMBOL_TEQUAL = 11,                    /* TEQUAL  */
  YYSYMBOL_TNOT = 12,                      /* TNOT  */
  YYSYMBOL_TCEQ = 13,                      /* TCEQ  */
  YYSYMBOL_TCNE = 14,                      /* TCNE  */
  YYSYMBOL_TCLT = 15,                      /* TCLT  */
  YYSYMBOL_TCLE = 16,                      /* TCLE  */
  YYSYMBOL_TCGT = 17,                      /* TCGT  */
  YYSYMBOL_TCGE = 18,                      /* TCGE  */
  YYSYMBOL_TLPAREN = 19,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 20,                   /* TRPAREN  */
  YYSYMBOL_TLBRACE = 21,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 22,                   /* TRBRACE  */
  YYSYMBOL_TDOT = 23,                      /* TDOT  */
  YYSYMBOL_TCOMMA = 24,                    /* TCOMMA  */
  YYSYMBOL_TPLUS = 25,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 26,                    /* TMINUS  */
  YYSYMBOL_TMUL = 27,                      /* TMUL  */
  YYSYMBOL_TDIV = 28,                      /* TDIV  */
  YYSYMBOL_TINC = 29,                      /* TINC  */
  YYSYMBOL_TDEC = 30,                      /* TDEC  */
  YYSYMBOL_TADD_ASSIGN = 31,               /* TADD_ASSIGN  */
  YYSYMBOL_TSUB_ASSIGN = 32,               /* TSUB_ASSIGN  */
  YYSYMBOL_TMUL_ASSIGN = 33,               /* TMUL_ASSIGN  */
  YYSYMBOL_TDIV_ASSIGN = 34,               /* TDIV_ASSIGN  */
  YYSYMBOL_TMOD_ASSIGN = 35,               /* TMOD_ASSIGN  */
  YYSYMBOL_TAND = 36,                      /* TAND  */
  YYSYMBOL_TOR = 37,                       /* TOR  */
  YYSYMBOL_TDOUBLE_COLON = 38,             /* TDOUBLE_COLON  */
  YYSYMBOL_TSEMICOLON = 39,                /* TSEMICOLON  */
  YYSYMBOL_TARROW = 40,                    /* TARROW  */
  YYSYMBOL_TSYM_PRINT = 41,                /* TSYM_PRINT  */
  YYSYMBOL_TSYM_READ = 42,                 /* TSYM_READ  */
  YYSYMBOL_TSYM_IF = 43,                   /* TSYM_IF  */
  YYSYMBOL_TSYM_ELSE = 44,                 /* TSYM_ELSE  */
  YYSYMBOL_TSYM_WHILE = 45,                /* TSYM_WHILE  */
  YYSYMBOL_TSYM_FN = 46,                   /* TSYM_FN  */
  YYSYMBOL_TSYM_CALL = 47,                 /* TSYM_CALL  */
  YYSYMBOL_TSYM_RESULT = 48,               /* TSYM_RESULT  */
  YYSYMBOL_TSYM_GUARD = 49,                /* TSYM_GUARD  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_block = 52,                     /* block  */
  YYSYMBOL_stmts = 53,                     /* stmts  */
  YYSYMBOL_stmt = 54,                      /* stmt  */
  YYSYMBOL_assign_op = 55,                 /* assign_op  */
  YYSYMBOL_var_type = 56,                  /* var_type  */
  YYSYMBOL_var_decl = 57,                  /* var_decl  */
  YYSYMBOL_var_assign = 58,                /* var_assign  */
  YYSYMBOL_print = 59,                     /* print  */
  YYSYMBOL_while_stmt = 60,                /* while_stmt  */
  YYSYMBOL_if_stmt = 61,                   /* if_stmt  */
  YYSYMBOL_rel_expr = 62,                  /* rel_expr  */
  YYSYMBOL_expr = 63,                      /* expr  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_factor = 65,                    /* factor  */
  YYSYMBOL_ident = 66,                     /* ident  */
  YYSYMBOL_rel_expr_op = 67,               /* rel_expr_op  */
  YYSYMBOL_expr_op = 68,                   /* expr_op  */
  YYSYMBOL_term_op = 69,                   /* term_op  */
  YYSYMBOL_unary_op = 70,                  /* unary_op  */
  YYSYMBOL_factor_var = 71,                /* factor_var  */
  YYSYMBOL_func_block = 72,                /* func_block  */
  YYSYMBOL_func_stmts = 73,                /* func_stmts  */
  YYSYMBOL_func_stmt = 74,                 /* func_stmt  */
  YYSYMBOL_call_args = 75,                 /* call_args  */
  YYSYMBOL_arg_decl = 76,                  /* arg_decl  */
  YYSYMBOL_func_decl_args = 77,            /* func_decl_args  */
  YYSYMBOL_func_decl = 78,                 /* func_decl  */
  YYSYMBOL_arg_name = 79,                  /* arg_name  */
  YYSYMBOL_func_arg_name = 80,             /* func_arg_name  */
  YYSYMBOL_func_assign = 81                /* func_assign  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    72,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    91,
      91,    91,    92,    92,    92,    92,    95,    95,    95,    98,
      99,   102,   103,   106,   109,   112,   113,   118,   119,   122,
     123,   126,   127,   129,   130,   131,   132,   133,   134,   137,
     140,   140,   140,   140,   140,   140,   140,   143,   143,   143,
     146,   146,   146,   149,   149,   149,   152,   153,   154,   158,
     159,   162,   163,   166,   167,   168,   169,   170,   173,   174,
     175,   178,   179,   183,   184,   187,   189,   191,   193,   197,
     200,   201,   204,   205,   206,   207
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TIDENTIFIER",
  "TFLOAT", "TINTEGER", "TSTRING", "TTYPE_STRING", "TTYPE_INT",
  "TTYPE_FLOAT", "TTYPE_VOID", "TEQUAL", "TNOT", "TCEQ", "TCNE", "TCLT",
  "TCLE", "TCGT", "TCGE", "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE",
  "TDOT", "TCOMMA", "TPLUS", "TMINUS", "TMUL", "TDIV", "TINC", "TDEC",
  "TADD_ASSIGN", "TSUB_ASSIGN", "TMUL_ASSIGN", "TDIV_ASSIGN",
  "TMOD_ASSIGN", "TAND", "TOR", "TDOUBLE_COLON", "TSEMICOLON", "TARROW",
  "TSYM_PRINT", "TSYM_READ", "TSYM_IF", "TSYM_ELSE", "TSYM_WHILE",
  "TSYM_FN", "TSYM_CALL", "TSYM_RESULT", "TSYM_GUARD", "$accept",
  "program", "block", "stmts", "stmt", "assign_op", "var_type", "var_decl",
  "var_assign", "print", "while_stmt", "if_stmt", "rel_expr", "expr",
  "term", "factor", "ident", "rel_expr_op", "expr_op", "term_op",
  "unary_op", "factor_var", "func_block", "func_stmts", "func_stmt",
  "call_args", "arg_decl", "func_decl_args", "func_decl", "arg_name",
  "func_arg_name", "func_assign", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,  -103,   -15,    65,    65,    21,    26,    86,  -103,    19,
      28,    34,    39,    41,   107,    53,    61,    65,  -103,  -103,
    -103,  -103,    65,  -103,  -103,    27,    21,    24,   131,    49,
      15,  -103,    65,  -103,    24,     6,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,    65,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,    65,    29,  -103,  -103,    82,    83,    85,    94,    63,
      -9,  -103,  -103,  -103,  -103,  -103,  -103,  -103,    65,  -103,
    -103,  -103,    65,  -103,  -103,  -103,    65,  -103,  -103,    98,
      13,    14,  -103,  -103,    17,  -103,  -103,    65,  -103,  -103,
    -103,    65,  -103,    79,    24,  -103,  -103,  -103,     7,  -103,
     112,    52,  -103,  -103,  -103,    88,  -103,   102,   -10,    98,
      21,  -103,  -103,    59,  -103,  -103,  -103,    77,    65,  -103,
      16,  -103,    98,   146,  -103,  -103,   126,   126,   143,  -103,
    -103,  -103,    65,  -103,    65,   116,  -103,  -103,  -103,    98,
    -103,   102,  -103,  -103,  -103,   119,  -103,    65,  -103,  -103,
     120,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,    49,     0,     0,     0,     0,     0,     2,     5,     0,
       0,     0,    11,    13,     0,    15,    17,     0,    67,    66,
      68,    63,     0,    65,    64,     0,     0,     0,    37,    39,
      41,    45,     0,    44,     0,     0,     1,     6,     9,     8,
      10,    12,    14,     0,    24,    25,    19,    20,    21,    22,
      23,     0,    29,    16,    18,     0,     0,     0,     0,     0,
      35,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,    62,     0,    43,    34,     0,
       0,     0,    89,    90,     0,    31,    32,     0,    33,    46,
      47,    78,     4,     0,     0,    38,    40,    42,     0,    92,
       0,     0,    28,    26,    27,     0,    81,    83,     0,     0,
       0,    30,    79,     0,     3,    36,    70,     0,     0,    73,
       0,    71,     0,     0,    88,    87,     0,     0,     0,    94,
      91,    48,     0,    74,     0,     0,    69,    72,    93,     0,
      82,    84,    86,    85,    80,     0,    76,     0,    95,    75,
       0,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,   -31,   101,    -5,  -103,   -94,  -103,  -103,  -103,
    -103,  -103,    -4,   -56,    89,   -27,     1,  -103,  -103,  -103,
    -103,  -103,  -102,  -103,    42,  -103,    36,  -103,  -103,    54,
      87,  -103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,    60,     7,     8,    51,   106,     9,    10,    11,
      12,    13,    27,    28,    29,    30,    31,    68,    72,    76,
      32,    33,    99,   120,   121,   113,   107,   108,    15,    83,
      84,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    14,    37,    78,    17,    77,    35,   129,    14,     1,
       1,   125,    95,    55,   127,    52,     1,    79,    56,     1,
     138,   102,   103,   104,     1,    80,    36,    58,   109,   116,
     128,   111,   140,   100,   143,    94,    82,   148,   136,    85,
      87,   110,    73,    74,    81,    59,    57,    86,     2,    97,
       3,    75,     4,     5,   105,   117,   118,     2,    38,     3,
      14,     4,     5,   115,   117,   118,     1,    39,     1,    18,
      19,    20,   123,    40,    69,    70,   110,    21,    41,   131,
      42,    82,     1,   132,    22,    92,    71,   112,    37,     1,
      23,    24,    53,   119,    14,   102,   103,   104,   124,    14,
      54,   114,    88,    89,     2,    90,     3,    25,     4,     5,
       1,    82,    26,    91,   135,   119,   133,   134,    43,    98,
       2,    14,     3,   122,     4,     5,   126,     2,   144,     3,
     145,     4,     5,   102,   103,   104,    44,    45,    46,    47,
      48,    49,    50,   150,    61,    62,    63,    64,    65,    66,
     102,   103,   104,   142,    67,   146,   147,   139,   149,   151,
      93,    96,   137,   141,   130,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
       4,     0,     7,    34,    19,    32,     5,   109,     7,     3,
       3,   105,    68,    17,    24,    14,     3,    11,    22,     3,
     122,     7,     8,     9,     3,    19,     0,    26,    11,    22,
      40,    87,   126,    20,   128,    44,    35,   139,    22,    43,
      11,    24,    27,    28,    38,    21,    19,    51,    41,    76,
      43,    36,    45,    46,    40,    48,    49,    41,    39,    43,
      59,    45,    46,    94,    48,    49,     3,    39,     3,     4,
       5,     6,    20,    39,    25,    26,    24,    12,    39,    20,
      39,    80,     3,    24,    19,    22,    37,    91,    93,     3,
      25,    26,    39,    98,    93,     7,     8,     9,    10,    98,
      39,    22,    20,    20,    41,    20,    43,    42,    45,    46,
       3,   110,    47,    19,   118,   120,    39,    40,    11,    21,
      41,   120,    43,    11,    45,    46,    24,    41,   132,    43,
     134,    45,    46,     7,     8,     9,    29,    30,    31,    32,
      33,    34,    35,   147,    13,    14,    15,    16,    17,    18,
       7,     8,     9,    10,    23,    39,    40,    11,    39,    39,
      59,    72,   120,   127,   110,    -1,    -1,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    41,    43,    45,    46,    51,    53,    54,    57,
      58,    59,    60,    61,    66,    78,    81,    19,     4,     5,
       6,    12,    19,    25,    26,    42,    47,    62,    63,    64,
      65,    66,    70,    71,    62,    66,     0,    54,    39,    39,
      39,    39,    39,    11,    29,    30,    31,    32,    33,    34,
      35,    55,    66,    39,    39,    62,    62,    19,    66,    21,
      52,    13,    14,    15,    16,    17,    18,    23,    67,    25,
      26,    37,    68,    27,    28,    36,    69,    65,    52,    11,
      19,    38,    66,    79,    80,    62,    62,    11,    20,    20,
      20,    19,    22,    53,    44,    63,    64,    65,    21,    72,
      20,    80,     7,     8,     9,    40,    56,    76,    77,    11,
      24,    63,    62,    75,    22,    52,    22,    48,    49,    54,
      73,    74,    11,    20,    10,    56,    24,    24,    40,    72,
      79,    20,    24,    39,    40,    62,    22,    74,    72,    11,
      56,    76,    10,    56,    62,    62,    39,    40,    72,    39,
      62,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    79,
      80,    80,    81,    81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     2,     0,     2,     2,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     3,     4,     3,     3,     5,     1,     3,     1,
       3,     1,     3,     2,     1,     1,     3,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     2,     1,     2,     4,     3,     5,     0,     1,
       3,     1,     3,     1,     3,     6,     6,     5,     5,     1,
       1,     3,     4,     6,     5,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* program: stmts  */
#line 64 "parser.y"
                { programBlock = (yyvsp[0].block); }
#line 1261 "parser.cpp"
    break;

  case 3: /* block: TLBRACE stmts TRBRACE  */
#line 67 "parser.y"
                              { (yyval.block) = (yyvsp[-1].block); }
#line 1267 "parser.cpp"
    break;

  case 4: /* block: TLBRACE TRBRACE  */
#line 68 "parser.y"
                        { (yyval.block) = new NBlock(); }
#line 1273 "parser.cpp"
    break;

  case 5: /* stmts: stmt  */
#line 71 "parser.y"
             { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1279 "parser.cpp"
    break;

  case 6: /* stmts: stmts stmt  */
#line 72 "parser.y"
                   { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt)); }
#line 1285 "parser.cpp"
    break;

  case 7: /* stmt: %empty  */
#line 77 "parser.y"
                          { (yyval.stmt) = new NEmpty(); }
#line 1291 "parser.cpp"
    break;

  case 29: /* var_decl: ident ident  */
#line 98 "parser.y"
                       { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[-1].ident), *(yyvsp[0].ident)); }
#line 1297 "parser.cpp"
    break;

  case 30: /* var_decl: ident ident TEQUAL expr  */
#line 99 "parser.y"
                                   { (yyval.stmt) = new NVariableDeclaration(*(yyvsp[-3].ident), *(yyvsp[-2].ident), (yyvsp[0].expr)); }
#line 1303 "parser.cpp"
    break;

  case 31: /* var_assign: ident TEQUAL rel_expr  */
#line 102 "parser.y"
                                   { (yyval.stmt) = new NAssignment(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1309 "parser.cpp"
    break;

  case 32: /* var_assign: ident assign_op rel_expr  */
#line 103 "parser.y"
                                      { (yyval.stmt) = new NAssignment(*(yyvsp[-2].ident), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1315 "parser.cpp"
    break;

  case 33: /* print: TSYM_PRINT TLPAREN rel_expr TRPAREN  */
#line 106 "parser.y"
                                            { (yyval.stmt) = new NPrint(*(yyvsp[-1].expr)); }
#line 1321 "parser.cpp"
    break;

  case 34: /* while_stmt: TSYM_WHILE rel_expr block  */
#line 109 "parser.y"
                                       { (yyval.stmt) = new NWhile(*(yyvsp[-1].expr), *(yyvsp[0].block)); }
#line 1327 "parser.cpp"
    break;

  case 35: /* if_stmt: TSYM_IF rel_expr block  */
#line 112 "parser.y"
                                 { (yyval.stmt) = new NIfStatement(*(yyvsp[-1].expr), *(yyvsp[0].block)); }
#line 1333 "parser.cpp"
    break;

  case 36: /* if_stmt: TSYM_IF rel_expr block TSYM_ELSE block  */
#line 113 "parser.y"
                                                 { (yyval.stmt) = new NIfStatement(*(yyvsp[-3].expr), *(yyvsp[-2].block), *(yyvsp[0].block)); }
#line 1339 "parser.cpp"
    break;

  case 38: /* rel_expr: expr rel_expr_op expr  */
#line 119 "parser.y"
                                 { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1345 "parser.cpp"
    break;

  case 40: /* expr: term expr_op term  */
#line 123 "parser.y"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1351 "parser.cpp"
    break;

  case 42: /* term: factor term_op factor  */
#line 127 "parser.y"
                             { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1357 "parser.cpp"
    break;

  case 43: /* factor: unary_op factor  */
#line 129 "parser.y"
                         { (yyval.expr) = new NUnaryOperator((yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1363 "parser.cpp"
    break;

  case 45: /* factor: ident  */
#line 131 "parser.y"
               { (yyval.ident) = (yyvsp[0].ident); }
#line 1369 "parser.cpp"
    break;

  case 46: /* factor: TLPAREN rel_expr TRPAREN  */
#line 132 "parser.y"
                                  { (yyval.expr) = (yyvsp[-1].expr); }
#line 1375 "parser.cpp"
    break;

  case 47: /* factor: TSYM_READ TLPAREN TRPAREN  */
#line 133 "parser.y"
                                   { (yyval.expr) = new NRead(); }
#line 1381 "parser.cpp"
    break;

  case 48: /* factor: TSYM_CALL ident TLPAREN call_args TRPAREN  */
#line 134 "parser.y"
                                                   { (yyval.expr) = new NMethodCall(*(yyvsp[-3].ident), *(yyvsp[-1].exprvec)); delete (yyvsp[-1].exprvec); }
#line 1387 "parser.cpp"
    break;

  case 49: /* ident: TIDENTIFIER  */
#line 137 "parser.y"
                    { (yyval.ident) = new NIdentifier(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1393 "parser.cpp"
    break;

  case 66: /* factor_var: TINTEGER  */
#line 152 "parser.y"
                      { (yyval.expr) = new NInteger(atol((yyvsp[0].string)->c_str())); delete (yyvsp[0].string);}
#line 1399 "parser.cpp"
    break;

  case 67: /* factor_var: TFLOAT  */
#line 153 "parser.y"
                    { (yyval.expr) = new NFloat(atof((yyvsp[0].string)->c_str())); delete (yyvsp[0].string);}
#line 1405 "parser.cpp"
    break;

  case 68: /* factor_var: TSTRING  */
#line 154 "parser.y"
                     { (yyval.expr) = new NString(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1411 "parser.cpp"
    break;

  case 69: /* func_block: TLBRACE func_stmts TRBRACE  */
#line 158 "parser.y"
                                        { (yyval.block) = (yyvsp[-1].block); }
#line 1417 "parser.cpp"
    break;

  case 70: /* func_block: TLBRACE TRBRACE  */
#line 159 "parser.y"
                             { (yyval.block) = new NBlock(); }
#line 1423 "parser.cpp"
    break;

  case 71: /* func_stmts: func_stmt  */
#line 162 "parser.y"
                       { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1429 "parser.cpp"
    break;

  case 72: /* func_stmts: func_stmts func_stmt  */
#line 163 "parser.y"
                             { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt)); }
#line 1435 "parser.cpp"
    break;

  case 74: /* func_stmt: TSYM_RESULT TSEMICOLON  */
#line 167 "parser.y"
                                   { (yyval.stmt) = new NResult(); }
#line 1441 "parser.cpp"
    break;

  case 75: /* func_stmt: TSYM_RESULT TARROW rel_expr TSEMICOLON  */
#line 168 "parser.y"
                                                   { (yyval.stmt) = new NResult(*(yyvsp[-1].expr)); }
#line 1447 "parser.cpp"
    break;

  case 76: /* func_stmt: TSYM_GUARD rel_expr TSEMICOLON  */
#line 169 "parser.y"
                                           { (yyval.stmt) = new NGuard(*(yyvsp[-1].expr)); }
#line 1453 "parser.cpp"
    break;

  case 77: /* func_stmt: TSYM_GUARD rel_expr TARROW rel_expr TSEMICOLON  */
#line 170 "parser.y"
                                                           { (yyval.stmt) = new NGuard(*(yyvsp[-3].expr), *(yyvsp[-1].expr)); }
#line 1459 "parser.cpp"
    break;

  case 78: /* call_args: %empty  */
#line 173 "parser.y"
                              { (yyval.exprvec) = new ExpressionList(); }
#line 1465 "parser.cpp"
    break;

  case 79: /* call_args: rel_expr  */
#line 174 "parser.y"
                     { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1471 "parser.cpp"
    break;

  case 80: /* call_args: call_args TCOMMA rel_expr  */
#line 175 "parser.y"
                                       { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1477 "parser.cpp"
    break;

  case 81: /* arg_decl: var_type  */
#line 178 "parser.y"
                    { (yyval.stmt) = new NArgDeclaration(*(yyvsp[0].token)); }
#line 1483 "parser.cpp"
    break;

  case 82: /* arg_decl: arg_decl TCOMMA var_type  */
#line 179 "parser.y"
                                    { (yyval.stmt) = new NArgDeclaration(*(yyvsp[0].token)); }
#line 1489 "parser.cpp"
    break;

  case 83: /* func_decl_args: arg_decl  */
#line 183 "parser.y"
                          { (yyval.arg_type_vec) = new ArgTypeList(); (yyval.arg_type_vec)->push_back((yyvsp[0].arg_decl)); }
#line 1495 "parser.cpp"
    break;

  case 84: /* func_decl_args: func_decl_args TCOMMA arg_decl  */
#line 184 "parser.y"
                                                { (yyvsp[-2].arg_type_vec)->push_back((yyvsp[0].arg_decl)); }
#line 1501 "parser.cpp"
    break;

  case 85: /* func_decl: TSYM_FN ident TDOUBLE_COLON func_decl_args TARROW var_type  */
#line 188 "parser.y"
            { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-4].ident), *(yyvsp[-2].arg_type_vec), *(yyvsp[0].token)); delete (yyvsp[-2].arg_type_vec); }
#line 1507 "parser.cpp"
    break;

  case 86: /* func_decl: TSYM_FN ident TDOUBLE_COLON func_decl_args TARROW TTYPE_VOID  */
#line 190 "parser.y"
            { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-4].ident), *(yyvsp[-2].arg_type_vec)); delete (yyvsp[-2].arg_type_vec); }
#line 1513 "parser.cpp"
    break;

  case 87: /* func_decl: TSYM_FN ident TDOUBLE_COLON TARROW var_type  */
#line 192 "parser.y"
            { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-3].ident), *(yyvsp[0].token)); }
#line 1519 "parser.cpp"
    break;

  case 88: /* func_decl: TSYM_FN ident TDOUBLE_COLON TARROW TTYPE_VOID  */
#line 194 "parser.y"
            { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-3].ident)); }
#line 1525 "parser.cpp"
    break;

  case 89: /* arg_name: ident  */
#line 197 "parser.y"
                 { (yyval.ident) = new NArgument(*(yyvsp[0].ident)); }
#line 1531 "parser.cpp"
    break;

  case 90: /* func_arg_name: arg_name  */
#line 200 "parser.y"
                         { (yyval.arg_name_vec) = new ArgList(); (yyval.arg_name_vec)->push_back((yyvsp[0].arg_name)); }
#line 1537 "parser.cpp"
    break;

  case 91: /* func_arg_name: func_arg_name TCOMMA arg_name  */
#line 201 "parser.y"
                                              { (yyvsp[-2].arg_name_vec)->push_back((yyvsp[0].arg_name)); }
#line 1543 "parser.cpp"
    break;

  case 92: /* func_assign: TSYM_FN ident TEQUAL func_block  */
#line 204 "parser.y"
                                              { (yyval.stmt) = new NFunctionAssignment(*(yyvsp[-2].ident), *(yyvsp[0].block)); }
#line 1549 "parser.cpp"
    break;

  case 93: /* func_assign: TSYM_FN ident TLPAREN TRPAREN TEQUAL func_block  */
#line 205 "parser.y"
                                                              { (yyval.stmt) = new NFunctionAssignment(*(yyvsp[-4].ident), *(yyvsp[0].block)); }
#line 1555 "parser.cpp"
    break;

  case 94: /* func_assign: TSYM_FN ident func_arg_name TEQUAL func_block  */
#line 206 "parser.y"
                                                            { (yyval.stmt) = new NFunctionAssignment(*(yyvsp[-3].ident), *(yyvsp[-2].arg_name_vec), *(yyvsp[0].block)); delete (yyvsp[-2].arg_name_vec);}
#line 1561 "parser.cpp"
    break;

  case 95: /* func_assign: TSYM_FN ident TLPAREN func_arg_name TRPAREN TEQUAL func_block  */
#line 207 "parser.y"
                                                                            { (yyval.stmt) = new NFunctionAssignment(*(yyvsp[-5].ident), *(yyvsp[-3].arg_name_vec), *(yyvsp[0].block)); delete (yyvsp[-3].arg_name_vec);}
#line 1567 "parser.cpp"
    break;


#line 1571 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 211 "parser.y"

