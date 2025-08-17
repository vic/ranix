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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/parser.y"

#include "node.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

/* Forward declarations of node helpers implemented in parser/nodetype.c */
Node* new_node(NodeType type, int token_start);
Node* new_node1(NodeType type, int token_start, Node* n1);
Node* new_node2(NodeType type, int token_start, Node* n1, Node* n2);
Node* new_node3(NodeType type, int token_start, Node* n1, Node* n2, Node* n3);
Node* op_node1(int op, int token_start, Node* n1);
Node* op_node2(int op, int token_start, Node* n1, Node* n2);
void set_node_type(Node* node, NodeType type);
void add_child(Node* parent, Node* child);
void set_token_end(Node* node, int token_end);

/* yyerror matching the generated parser expectations */
void yyerror(void **ast_root, void *scanner, const char *s) {
    (void)ast_root; (void)scanner;
    fprintf(stderr, "parse error: %s\n", s);
}

/* yylex prototype using void* so it's visible before YYSTYPE is defined in the generated file */
int yylex(void *yylval_param, void *scanner);


#line 99 "parser/parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSERT_ = 3,                    /* ASSERT_  */
  YYSYMBOL_IF_ = 4,                        /* IF_  */
  YYSYMBOL_THEN = 5,                       /* THEN  */
  YYSYMBOL_ELSE_ = 6,                      /* ELSE_  */
  YYSYMBOL_LET = 7,                        /* LET  */
  YYSYMBOL_IN = 8,                         /* IN  */
  YYSYMBOL_WITH = 9,                       /* WITH  */
  YYSYMBOL_OR_ = 10,                       /* OR_  */
  YYSYMBOL_REC = 11,                       /* REC  */
  YYSYMBOL_INHERIT = 12,                   /* INHERIT  */
  YYSYMBOL_ELLIPSIS = 13,                  /* ELLIPSIS  */
  YYSYMBOL_INTERP = 14,                    /* INTERP  */
  YYSYMBOL_SPACE = 15,                     /* SPACE  */
  YYSYMBOL_COMMENT = 16,                   /* COMMENT  */
  YYSYMBOL_II = 17,                        /* II  */
  YYSYMBOL_URI = 18,                       /* URI  */
  YYSYMBOL_PATH = 19,                      /* PATH  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_INT_ = 21,                      /* INT_  */
  YYSYMBOL_T_ID = 22,                      /* T_ID  */
  YYSYMBOL_TEXT = 23,                      /* TEXT  */
  YYSYMBOL_ARG_ID = 24,                    /* ARG_ID  */
  YYSYMBOL_ARG_BRACKET = 25,               /* ARG_BRACKET  */
  YYSYMBOL_26_ = 26,                       /* ':'  */
  YYSYMBOL_27_ = 27,                       /* '@'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '"'  */
  YYSYMBOL_31_ = 31,                       /* '.'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_IMPL = 39,                      /* IMPL  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_EQ = 42,                        /* EQ  */
  YYSYMBOL_NEQ = 43,                       /* NEQ  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_LEQ = 46,                       /* LEQ  */
  YYSYMBOL_GEQ = 47,                       /* GEQ  */
  YYSYMBOL_UPDATE = 48,                    /* UPDATE  */
  YYSYMBOL_49_ = 49,                       /* '!'  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '*'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_CONCAT = 54,                    /* CONCAT  */
  YYSYMBOL_55_ = 55,                       /* '?'  */
  YYSYMBOL_NEGATE = 56,                    /* NEGATE  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Main = 58,                      /* Main  */
  YYSYMBOL_Expression = 59,                /* Expression  */
  YYSYMBOL_Interp = 60,                    /* Interp  */
  YYSYMBOL_String = 61,                    /* String  */
  YYSYMBOL_ID = 62,                        /* ID  */
  YYSYMBOL_Atom = 63,                      /* Atom  */
  YYSYMBOL_Select = 64,                    /* Select  */
  YYSYMBOL_Apply = 65,                     /* Apply  */
  YYSYMBOL_Op = 66,                        /* Op  */
  YYSYMBOL_InterpID = 67,                  /* InterpID  */
  YYSYMBOL_AttrPath = 68,                  /* AttrPath  */
  YYSYMBOL_List = 69,                      /* List  */
  YYSYMBOL_Binds = 70,                     /* Binds  */
  YYSYMBOL_InheritList = 71,               /* InheritList  */
  YYSYMBOL_Function = 72,                  /* Function  */
  YYSYMBOL_ArgSet = 73,                    /* ArgSet  */
  YYSYMBOL_Arg = 74                        /* Arg  */
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,    49,    30,     2,     2,     2,     2,     2,
      32,    33,    52,    50,    28,    51,    31,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    29,
      44,    38,    45,    55,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    39,    40,    41,    42,    43,    46,    47,    48,    54,
      56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    71,    72,    74,    76,    78,    80,    84,
      90,    91,    93,    98,   103,   105,   107,   109,   111,   112,
     114,   116,   118,   120,   122,   127,   128,   130,   135,   136,
     141,   142,   144,   146,   148,   150,   152,   154,   156,   158,
     160,   162,   164,   166,   168,   170,   172,   174,   176,   181,
     182,   184,   185,   190,   192,   198,   199,   205,   206,   208,
     210,   216,   217,   222,   224,   226,   228,   230,   236,   237,
     239,   241,   246,   248
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
  "\"end of file\"", "error", "\"invalid token\"", "ASSERT_", "IF_",
  "THEN", "ELSE_", "LET", "IN", "WITH", "OR_", "REC", "INHERIT",
  "ELLIPSIS", "INTERP", "SPACE", "COMMENT", "II", "URI", "PATH", "FLOAT",
  "INT_", "T_ID", "TEXT", "ARG_ID", "ARG_BRACKET", "':'", "'@'", "','",
  "';'", "'\"'", "'.'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'='",
  "IMPL", "OR", "AND", "EQ", "NEQ", "'<'", "'>'", "LEQ", "GEQ", "UPDATE",
  "'!'", "'+'", "'-'", "'*'", "'/'", "CONCAT", "'?'", "NEGATE", "$accept",
  "Main", "Expression", "Interp", "String", "ID", "Atom", "Select",
  "Apply", "Op", "InterpID", "AttrPath", "List", "Binds", "InheritList",
  "Function", "ArgSet", "Arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     127,   127,   127,   -91,   127,   -18,   -91,   -91,   -91,   -91,
     -91,   -91,    65,    13,   -91,   127,   -91,   -91,   147,   147,
      24,   -91,   -91,    25,   -91,   189,   187,   -91,     8,    56,
      86,    43,   -91,    76,   127,    63,   -91,    40,    75,    74,
       6,    81,   169,    48,   120,   -91,   -91,    95,   -91,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,    95,   127,   127,   127,   -91,    89,
     127,   -91,   -91,   -91,   -91,    36,   127,    67,   -91,   -91,
     -91,   -91,    13,   127,    96,    13,   -91,   -91,   -91,   -91,
     -91,    -3,   187,   202,   216,   230,   230,   238,   238,   238,
     238,   238,   101,   101,    29,    29,    29,    87,   -91,   122,
     -91,   127,     1,    92,    57,    95,   127,   -91,   -91,   100,
     -91,   127,    35,   -91,   189,   127,    99,   -91,   -91,   -91,
     -91,   -91,   104,   113,   -91,   117,   124,   -91,   -91,   -91,
     -91,   127,   127,   127,    97,   -91,   -91,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    57,     0,     0,    10,    14,    15,    16,
      17,    13,     0,    68,    10,     0,    55,    57,     0,     0,
       0,     2,    18,    25,    28,    30,     3,     8,     0,     0,
       0,     0,    57,     0,     0,     0,    70,    72,     0,    69,
       0,     0,     0,     0,    38,    31,     1,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    61,
       0,    10,    51,    49,    53,     0,     0,     0,    20,    11,
      12,    63,    68,     0,     0,    68,    19,    21,    22,    56,
      23,    26,    48,    47,    46,    45,    44,    43,    42,    41,
      40,    39,    37,    36,    35,    34,    33,    32,     4,     0,
       6,     0,     0,     0,     0,     0,     0,     7,    24,     0,
      73,     0,     0,    71,     0,     0,     0,    59,    62,     9,
      52,    54,     0,     0,    64,     0,     0,    27,     5,    61,
      58,     0,     0,     0,     0,    65,    67,    66,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,    -1,   -28,    -8,    -9,   -91,   -23,   -91,   -10,
     -90,   -37,   -91,     0,    21,   -91,   -69,   -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    20,    21,    72,    33,    22,    23,    24,    25,    26,
      74,    75,    42,    30,   112,    27,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    29,    48,    31,    37,    80,    40,   124,    44,    45,
      91,    68,    80,   119,    41,    70,   123,    43,    32,    89,
      70,    73,   128,    11,    46,   131,    36,   107,   115,    79,
     127,    71,    77,    81,    73,    11,    86,    65,    73,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   128,    73,    47,    11,    68,   135,
      69,    66,    70,   114,   108,   109,   110,   115,    73,   113,
      11,    70,    76,    37,   116,   117,    37,    68,    71,    69,
      79,    70,   120,    63,    64,    90,    80,   130,    82,    11,
      70,    34,    35,    78,    67,    83,    68,    71,    69,    79,
      70,   137,    85,    73,   118,    68,    73,    68,    11,    70,
     126,    70,    84,   136,    87,   132,    71,    11,   115,    11,
     134,   111,   121,   122,   138,    71,   148,    71,   125,   129,
       1,     2,   139,   140,     3,    73,     4,   133,     5,   141,
     145,   146,   147,   142,     6,     7,     8,     9,    10,    11,
     143,    12,    13,    61,    62,    63,    64,    14,     5,    15,
     144,    16,     0,    17,     6,     7,     8,     9,    10,    11,
      59,    60,    61,    62,    63,    64,    18,    14,    19,    15,
       5,    16,     0,    17,     0,     0,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,    18,     0,    19,    14,
       5,    15,     0,    16,    88,    17,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,     0,     0,     0,    14,
       0,    15,     0,    16,     0,    17,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,    59,    60,    61,
      62,    63,    64,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    52,    53,
      54,    55,    56,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    -1,    -1,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    58,     0,    59,    60,
      61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       1,     2,    25,     4,    13,    33,    14,    10,    18,    19,
      47,    10,    40,    82,    15,    14,    85,    17,    36,    42,
      14,    30,   112,    22,     0,   115,    13,    64,    31,    23,
      29,    30,    32,    34,    43,    22,    30,    29,    47,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   144,    64,    31,    22,    10,    24,
      12,     5,    14,    71,    65,    66,    67,    31,    77,    70,
      22,    14,    29,    82,    38,    76,    85,    10,    30,    12,
      23,    14,    83,    54,    55,    37,   114,    30,    25,    22,
      14,    26,    27,    17,     8,    55,    10,    30,    12,    23,
      14,   124,    28,   112,    37,    10,   115,    10,    22,    14,
     111,    14,    37,   122,    33,   116,    30,    22,    31,    22,
     121,    32,    26,    27,   125,    30,    29,    30,     6,    37,
       3,     4,    33,    29,     7,   144,     9,    37,    11,    26,
     141,   142,   143,    26,    17,    18,    19,    20,    21,    22,
      26,    24,    25,    52,    53,    54,    55,    30,    11,    32,
     139,    34,    -1,    36,    17,    18,    19,    20,    21,    22,
      50,    51,    52,    53,    54,    55,    49,    30,    51,    32,
      11,    34,    -1,    36,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    49,    -1,    51,    30,
      11,    32,    -1,    34,    35,    36,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,    34,    -1,    36,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    48,    -1,    50,    51,
      52,    53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     7,     9,    11,    17,    18,    19,    20,
      21,    22,    24,    25,    30,    32,    34,    36,    49,    51,
      58,    59,    62,    63,    64,    65,    66,    72,    59,    59,
      70,    59,    36,    61,    26,    27,    13,    62,    73,    74,
      61,    59,    69,    70,    66,    66,     0,    31,    64,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    50,
      51,    52,    53,    54,    55,    29,     5,     8,    10,    12,
      14,    30,    60,    62,    67,    68,    29,    70,    17,    23,
      60,    59,    25,    55,    37,    28,    30,    33,    35,    64,
      37,    68,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    68,    59,    59,
      59,    32,    71,    59,    61,    31,    38,    59,    37,    73,
      59,    26,    27,    73,    10,     6,    59,    29,    67,    37,
      30,    67,    59,    37,    59,    24,    62,    64,    59,    33,
      29,    26,    26,    26,    71,    59,    59,    59,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    59,    59,    60,
      61,    61,    61,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     4,     6,     4,     4,     1,     3,
       0,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     4,     1,     3,     5,     1,     2,
       1,     2,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     1,     3,     0,     2,     0,     5,     4,
       7,     0,     2,     3,     5,     7,     7,     7,     0,     1,
       1,     3,     1,     3
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
        yyerror (ast_root, scanner, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, ast_root, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void** ast_root, void* scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast_root);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void** ast_root, void* scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast_root, scanner);
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
                 int yyrule, void** ast_root, void* scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], ast_root, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast_root, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void** ast_root, void* scanner)
{
  YY_USE (yyvaluep);
  YY_USE (ast_root);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void** ast_root, void* scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, scanner);
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
  case 2: /* Main: Expression  */
#line 67 "parser/parser.y"
{ *ast_root = (yyvsp[0].node); }
#line 1291 "parser/parser.c"
    break;

  case 4: /* Expression: ASSERT_ Expression ';' Expression  */
#line 73 "parser/parser.y"
{ (yyval.node) = new_node2(ASSERT_NODE, (yyvsp[-3].token), (yyvsp[-2].node), (yyvsp[0].node)); set_token_end((yyval.node), (yyvsp[-1].token)); }
#line 1297 "parser/parser.c"
    break;

  case 5: /* Expression: IF_ Expression THEN Expression ELSE_ Expression  */
#line 75 "parser/parser.y"
{ (yyval.node) = new_node3(IF_NODE, (yyvsp[-5].token), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); set_token_end((yyval.node), (yyvsp[-3].token)); }
#line 1303 "parser/parser.c"
    break;

  case 6: /* Expression: LET Binds IN Expression  */
#line 77 "parser/parser.y"
{ (yyval.node) = new_node2(LET_NODE, (yyvsp[-3].token), (yyvsp[-2].node), (yyvsp[0].node)); set_token_end((yyval.node), (yyvsp[-1].token)); }
#line 1309 "parser/parser.c"
    break;

  case 7: /* Expression: WITH Expression ';' Expression  */
#line 79 "parser/parser.y"
{ (yyval.node) = new_node2(WITH_NODE, (yyvsp[-3].token), (yyvsp[-2].node), (yyvsp[0].node)); set_token_end((yyval.node), (yyvsp[-1].token)); }
#line 1315 "parser/parser.c"
    break;

  case 9: /* Interp: INTERP Expression '}'  */
#line 85 "parser/parser.y"
{ (yyval.node) = new_node1(INTERP_NODE, (yyvsp[-2].token), (yyvsp[-1].node)); set_token_end((yyval.node), (yyvsp[0].token)); }
#line 1321 "parser/parser.c"
    break;

  case 10: /* String: %empty  */
#line 90 "parser/parser.y"
{ (yyval.node) = new_node(STRING_NODE, 0); }
#line 1327 "parser/parser.c"
    break;

  case 11: /* String: String TEXT  */
#line 92 "parser/parser.y"
{ add_child((yyvsp[-1].node), new_node(TEXT_NODE, (yyvsp[0].token))); (yyval.node) = (yyvsp[-1].node); }
#line 1333 "parser/parser.c"
    break;

  case 12: /* String: String Interp  */
#line 94 "parser/parser.y"
{ add_child((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1339 "parser/parser.c"
    break;

  case 13: /* ID: T_ID  */
#line 99 "parser/parser.y"
{ (yyval.node) = new_node(ID_NODE, (yyvsp[0].token)); }
#line 1345 "parser/parser.c"
    break;

  case 14: /* Atom: URI  */
#line 104 "parser/parser.y"
{ (yyval.node) = new_node(URI_NODE, (yyvsp[0].token)); }
#line 1351 "parser/parser.c"
    break;

  case 15: /* Atom: PATH  */
#line 106 "parser/parser.y"
{ (yyval.node) = new_node(PATH_NODE, (yyvsp[0].token)); }
#line 1357 "parser/parser.c"
    break;

  case 16: /* Atom: FLOAT  */
#line 108 "parser/parser.y"
{ (yyval.node) = new_node(FLOAT_NODE, (yyvsp[0].token)); }
#line 1363 "parser/parser.c"
    break;

  case 17: /* Atom: INT_  */
#line 110 "parser/parser.y"
{ (yyval.node) = new_node(INT_NODE, (yyvsp[0].token)); }
#line 1369 "parser/parser.c"
    break;

  case 19: /* Atom: '"' String '"'  */
#line 113 "parser/parser.y"
{ set_token_end((yyvsp[-1].node), (yyvsp[0].token)); (yyval.node) = (yyvsp[-1].node); }
#line 1375 "parser/parser.c"
    break;

  case 20: /* Atom: II String II  */
#line 115 "parser/parser.y"
{ set_node_type((yyvsp[-1].node), I_STRING_NODE); set_token_end((yyvsp[-1].node), (yyvsp[0].token)); (yyval.node) = (yyvsp[-1].node); }
#line 1381 "parser/parser.c"
    break;

  case 21: /* Atom: '(' Expression ')'  */
#line 117 "parser/parser.y"
{ (yyval.node) = new_node1(PARENS_NODE, (yyvsp[-2].token), (yyvsp[-1].node)); set_token_end((yyval.node), (yyvsp[0].token)); }
#line 1387 "parser/parser.c"
    break;

  case 22: /* Atom: '[' List ']'  */
#line 119 "parser/parser.y"
{ set_token_end((yyvsp[-1].node), (yyvsp[0].token)); (yyval.node) = (yyvsp[-1].node); }
#line 1393 "parser/parser.c"
    break;

  case 23: /* Atom: '{' Binds '}'  */
#line 121 "parser/parser.y"
{ set_node_type((yyvsp[-1].node), SET_NODE); set_token_end((yyvsp[-1].node), (yyvsp[0].token)); (yyval.node) = (yyvsp[-1].node); }
#line 1399 "parser/parser.c"
    break;

  case 24: /* Atom: REC '{' Binds '}'  */
#line 123 "parser/parser.y"
{ set_node_type((yyvsp[-1].node), REC_SET_NODE); set_token_end((yyvsp[-1].node), (yyvsp[0].token)); (yyval.node) = (yyvsp[-1].node); }
#line 1405 "parser/parser.c"
    break;

  case 26: /* Select: Atom '.' AttrPath  */
#line 129 "parser/parser.y"
{ (yyval.node) = new_node2(SELECT_NODE, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1411 "parser/parser.c"
    break;

  case 27: /* Select: Atom '.' AttrPath OR_ Select  */
#line 131 "parser/parser.y"
{ (yyval.node) = new_node3(SELECT_OR_NODE, (yyvsp[-3].token), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); set_token_end((yyval.node), (yyvsp[-1].token)); }
#line 1417 "parser/parser.c"
    break;

  case 29: /* Apply: Apply Select  */
#line 137 "parser/parser.y"
{ (yyval.node) = new_node2(APPLY_NODE, 0, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1423 "parser/parser.c"
    break;

  case 31: /* Op: '-' Op  */
#line 143 "parser/parser.y"
{ (yyval.node) = op_node1('-', (yyvsp[-1].token), (yyvsp[0].node)); }
#line 1429 "parser/parser.c"
    break;

  case 32: /* Op: Op '?' AttrPath  */
#line 145 "parser/parser.y"
{ (yyval.node) = op_node2('?', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1435 "parser/parser.c"
    break;

  case 33: /* Op: Op CONCAT Op  */
#line 147 "parser/parser.y"
{ (yyval.node) = op_node2(CONCAT, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1441 "parser/parser.c"
    break;

  case 34: /* Op: Op '/' Op  */
#line 149 "parser/parser.y"
{ (yyval.node) = op_node2('/', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1447 "parser/parser.c"
    break;

  case 35: /* Op: Op '*' Op  */
#line 151 "parser/parser.y"
{ (yyval.node) = op_node2('*', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1453 "parser/parser.c"
    break;

  case 36: /* Op: Op '-' Op  */
#line 153 "parser/parser.y"
{ (yyval.node) = op_node2('-', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1459 "parser/parser.c"
    break;

  case 37: /* Op: Op '+' Op  */
#line 155 "parser/parser.y"
{ (yyval.node) = op_node2('+', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1465 "parser/parser.c"
    break;

  case 38: /* Op: '!' Op  */
#line 157 "parser/parser.y"
{ (yyval.node) = op_node1('!', (yyvsp[-1].token), (yyvsp[0].node)); }
#line 1471 "parser/parser.c"
    break;

  case 39: /* Op: Op UPDATE Op  */
#line 159 "parser/parser.y"
{ (yyval.node) = op_node2(UPDATE, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1477 "parser/parser.c"
    break;

  case 40: /* Op: Op GEQ Op  */
#line 161 "parser/parser.y"
{ (yyval.node) = op_node2(GEQ, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1483 "parser/parser.c"
    break;

  case 41: /* Op: Op LEQ Op  */
#line 163 "parser/parser.y"
{ (yyval.node) = op_node2(LEQ, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1489 "parser/parser.c"
    break;

  case 42: /* Op: Op '>' Op  */
#line 165 "parser/parser.y"
{ (yyval.node) = op_node2('>', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1495 "parser/parser.c"
    break;

  case 43: /* Op: Op '<' Op  */
#line 167 "parser/parser.y"
{ (yyval.node) = op_node2('<', (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1501 "parser/parser.c"
    break;

  case 44: /* Op: Op NEQ Op  */
#line 169 "parser/parser.y"
{ (yyval.node) = op_node2(NEQ, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1507 "parser/parser.c"
    break;

  case 45: /* Op: Op EQ Op  */
#line 171 "parser/parser.y"
{ (yyval.node) = op_node2(EQ, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1513 "parser/parser.c"
    break;

  case 46: /* Op: Op AND Op  */
#line 173 "parser/parser.y"
{ (yyval.node) = op_node2(AND, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1519 "parser/parser.c"
    break;

  case 47: /* Op: Op OR Op  */
#line 175 "parser/parser.y"
{ (yyval.node) = op_node2(OR, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1525 "parser/parser.c"
    break;

  case 48: /* Op: Op IMPL Op  */
#line 177 "parser/parser.y"
{ (yyval.node) = op_node2(IMPL, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1531 "parser/parser.c"
    break;

  case 50: /* InterpID: OR_  */
#line 183 "parser/parser.y"
{ (yyval.node) = new_node(ID_NODE, (yyvsp[0].token)); }
#line 1537 "parser/parser.c"
    break;

  case 52: /* InterpID: '"' String '"'  */
#line 186 "parser/parser.y"
{ set_token_end((yyvsp[-1].node), (yyvsp[0].token)); (yyval.node) = (yyvsp[-1].node); }
#line 1543 "parser/parser.c"
    break;

  case 53: /* AttrPath: InterpID  */
#line 191 "parser/parser.y"
{ (yyval.node) = new_node1(ATTR_PATH_NODE, 0, (yyvsp[0].node)); }
#line 1549 "parser/parser.c"
    break;

  case 54: /* AttrPath: AttrPath '.' InterpID  */
#line 193 "parser/parser.y"
{ add_child((yyvsp[-2].node), (yyvsp[0].node)); set_token_end((yyvsp[-2].node), 0); (yyval.node) = (yyvsp[-2].node); }
#line 1555 "parser/parser.c"
    break;

  case 55: /* List: %empty  */
#line 198 "parser/parser.y"
{ (yyval.node) = new_node(LIST_NODE, 0); }
#line 1561 "parser/parser.c"
    break;

  case 56: /* List: List Select  */
#line 200 "parser/parser.y"
{ add_child((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1567 "parser/parser.c"
    break;

  case 57: /* Binds: %empty  */
#line 205 "parser/parser.y"
{ (yyval.node) = new_node(BINDS_NODE, 0); }
#line 1573 "parser/parser.c"
    break;

  case 58: /* Binds: Binds AttrPath '=' Expression ';'  */
#line 207 "parser/parser.y"
{ add_child((yyvsp[-4].node), new_node2(BIND_NODE, (yyvsp[-2].token), (yyvsp[-3].node), (yyvsp[-1].node))); (yyval.node) = (yyvsp[-4].node); }
#line 1579 "parser/parser.c"
    break;

  case 59: /* Binds: Binds INHERIT InheritList ';'  */
#line 209 "parser/parser.y"
{ add_child((yyvsp[-3].node), new_node1(INHERIT_NODE, (yyvsp[-2].token), (yyvsp[-1].node))); (yyval.node) = (yyvsp[-3].node); }
#line 1585 "parser/parser.c"
    break;

  case 60: /* Binds: Binds INHERIT '(' Expression ')' InheritList ';'  */
#line 211 "parser/parser.y"
{ add_child((yyvsp[-6].node), new_node2(INHERIT_FROM_NODE, (yyvsp[-5].token), (yyvsp[-3].node), (yyvsp[-1].node))); (yyval.node) = (yyvsp[-6].node); }
#line 1591 "parser/parser.c"
    break;

  case 61: /* InheritList: %empty  */
#line 216 "parser/parser.y"
{ (yyval.node) = new_node(INHERIT_LIST_NODE, 0); }
#line 1597 "parser/parser.c"
    break;

  case 62: /* InheritList: InheritList InterpID  */
#line 218 "parser/parser.y"
{ add_child((yyvsp[-1].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node); }
#line 1603 "parser/parser.c"
    break;

  case 63: /* Function: ARG_ID ':' Expression  */
#line 223 "parser/parser.y"
{ (yyval.node) = new_node2(FUNCTION_NODE, (yyvsp[-1].token), new_node(ID_NODE, (yyvsp[-2].token)), (yyvsp[0].node)); }
#line 1609 "parser/parser.c"
    break;

  case 64: /* Function: ARG_BRACKET ArgSet '}' ':' Expression  */
#line 225 "parser/parser.y"
{ (yyval.node) = new_node2(FUNCTION_NODE, (yyvsp[-1].token), (yyvsp[-3].node), (yyvsp[0].node)); set_token_end((yyvsp[-3].node), (yyvsp[-2].token)); }
#line 1615 "parser/parser.c"
    break;

  case 65: /* Function: ARG_ID '@' ARG_BRACKET ArgSet '}' ':' Expression  */
#line 227 "parser/parser.y"
{ (yyval.node) = new_node3(FUNCTION_NODE, (yyvsp[-5].token), new_node(ID_NODE, (yyvsp[-6].token)), (yyvsp[-3].node), (yyvsp[0].node)); set_token_end((yyvsp[-3].node), (yyvsp[-2].token)); }
#line 1621 "parser/parser.c"
    break;

  case 66: /* Function: ARG_BRACKET ArgSet '}' '@' ID ':' Expression  */
#line 229 "parser/parser.y"
{ (yyval.node) = new_node3(FUNCTION_NODE, (yyvsp[-3].token), (yyvsp[-2].node), (yyvsp[-5].node), (yyvsp[0].node)); set_token_end((yyvsp[-5].node), (yyvsp[-4].token)); }
#line 1627 "parser/parser.c"
    break;

  case 67: /* Function: ARG_BRACKET ArgSet '}' '@' ARG_ID ':' Expression  */
#line 231 "parser/parser.y"
{ (yyval.node) = new_node3(FUNCTION_NODE, (yyvsp[-3].token), new_node(ID_NODE, (yyvsp[-2].token)), (yyvsp[-5].node), (yyvsp[0].node)); set_token_end((yyvsp[-5].node), (yyvsp[-4].token)); }
#line 1633 "parser/parser.c"
    break;

  case 68: /* ArgSet: %empty  */
#line 236 "parser/parser.y"
{ (yyval.node) = new_node(ARG_SET_NODE, 0); }
#line 1639 "parser/parser.c"
    break;

  case 69: /* ArgSet: Arg  */
#line 238 "parser/parser.y"
{ (yyval.node) = new_node1(ARG_SET_NODE, 0, (yyvsp[0].node)); }
#line 1645 "parser/parser.c"
    break;

  case 70: /* ArgSet: ELLIPSIS  */
#line 240 "parser/parser.y"
{ (yyval.node) = new_node1(ARG_SET_NODE, 0, new_node(ARG_NODE, (yyvsp[0].token))); }
#line 1651 "parser/parser.c"
    break;

  case 71: /* ArgSet: Arg ',' ArgSet  */
#line 242 "parser/parser.y"
{ add_child((yyvsp[0].node), (yyvsp[-2].node)); (yyval.node) = (yyvsp[0].node); }
#line 1657 "parser/parser.c"
    break;

  case 72: /* Arg: ID  */
#line 247 "parser/parser.y"
{ (yyval.node) = new_node1(ARG_NODE, 0, (yyvsp[0].node)); }
#line 1663 "parser/parser.c"
    break;

  case 73: /* Arg: ID '?' Expression  */
#line 249 "parser/parser.y"
{ (yyval.node) = new_node2(ARG_NODE, (yyvsp[-1].token), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1669 "parser/parser.c"
    break;


#line 1673 "parser/parser.c"

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
      yyerror (ast_root, scanner, YY_("syntax error"));
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
                      yytoken, &yylval, ast_root, scanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast_root, scanner);
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
  yyerror (ast_root, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, ast_root, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast_root, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 252 "parser/parser.y"

