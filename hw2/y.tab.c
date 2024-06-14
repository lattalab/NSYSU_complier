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
#line 1 "B103040045.y"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

// create symbol table
struct symtab{
	char name[40];
	char type[20];
	char undefinedFlag;
};
struct symtab symtable[100];
int idx = 0;
int idlistCounter = 0;

char flag = 1;
extern unsigned line_num;
extern int yylex();
extern void yyerror(const char *error);
static char check(const char *id);


#line 95 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DOUBLE = 258,                  /* DOUBLE  */
    ID = 259,                      /* ID  */
    INTEGER = 260,                 /* INTEGER  */
    REAL = 261,                    /* REAL  */
    SINGLE = 262,                  /* SINGLE  */
    STR = 263,                     /* STR  */
    STRING = 264,                  /* STRING  */
    INT = 265,                     /* INT  */
    REAL_NUM = 266,                /* REAL_NUM  */
    ABSOLUTE = 267,                /* ABSOLUTE  */
    AND = 268,                     /* AND  */
    ARRAY = 269,                   /* ARRAY  */
    BEG = 270,                     /* BEG  */
    BREAK = 271,                   /* BREAK  */
    CASE = 272,                    /* CASE  */
    CONST = 273,                   /* CONST  */
    CONTINUE = 274,                /* CONTINUE  */
    DO = 275,                      /* DO  */
    ELSE = 276,                    /* ELSE  */
    END = 277,                     /* END  */
    FOR = 278,                     /* FOR  */
    FUNCTION = 279,                /* FUNCTION  */
    IF = 280,                      /* IF  */
    MOD = 281,                     /* MOD  */
    NIL = 282,                     /* NIL  */
    NOT = 283,                     /* NOT  */
    OBJECT = 284,                  /* OBJECT  */
    OF = 285,                      /* OF  */
    OR = 286,                      /* OR  */
    PROGRAM = 287,                 /* PROGRAM  */
    READ = 288,                    /* READ  */
    READLN = 289,                  /* READLN  */
    THEN = 290,                    /* THEN  */
    TO = 291,                      /* TO  */
    VAR = 292,                     /* VAR  */
    WHILE = 293,                   /* WHILE  */
    WRITE = 294,                   /* WRITE  */
    WRITELN = 295,                 /* WRITELN  */
    LT = 296,                      /* LT  */
    EQUAL = 297,                   /* EQUAL  */
    GT = 298,                      /* GT  */
    ASSIGN = 299,                  /* ASSIGN  */
    LE = 300,                      /* LE  */
    GE = 301,                      /* GE  */
    NE = 302,                      /* NE  */
    LP = 303,                      /* LP  */
    RP = 304,                      /* RP  */
    XID = 305,                     /* XID  */
    XREAL = 306                    /* XREAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DOUBLE 258
#define ID 259
#define INTEGER 260
#define REAL 261
#define SINGLE 262
#define STR 263
#define STRING 264
#define INT 265
#define REAL_NUM 266
#define ABSOLUTE 267
#define AND 268
#define ARRAY 269
#define BEG 270
#define BREAK 271
#define CASE 272
#define CONST 273
#define CONTINUE 274
#define DO 275
#define ELSE 276
#define END 277
#define FOR 278
#define FUNCTION 279
#define IF 280
#define MOD 281
#define NIL 282
#define NOT 283
#define OBJECT 284
#define OF 285
#define OR 286
#define PROGRAM 287
#define READ 288
#define READLN 289
#define THEN 290
#define TO 291
#define VAR 292
#define WHILE 293
#define WRITE 294
#define WRITELN 295
#define LT 296
#define EQUAL 297
#define GT 298
#define ASSIGN 299
#define LE 300
#define GE 301
#define NE 302
#define LP 303
#define RP 304
#define XID 305
#define XREAL 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "B103040045.y"

	char *str;

#line 254 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DOUBLE = 3,                     /* DOUBLE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_SINGLE = 7,                     /* SINGLE  */
  YYSYMBOL_STR = 8,                        /* STR  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_REAL_NUM = 11,                  /* REAL_NUM  */
  YYSYMBOL_ABSOLUTE = 12,                  /* ABSOLUTE  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_ARRAY = 14,                     /* ARRAY  */
  YYSYMBOL_BEG = 15,                       /* BEG  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_END = 22,                       /* END  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_FUNCTION = 24,                  /* FUNCTION  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_NIL = 27,                       /* NIL  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_OBJECT = 29,                    /* OBJECT  */
  YYSYMBOL_OF = 30,                        /* OF  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_PROGRAM = 32,                   /* PROGRAM  */
  YYSYMBOL_READ = 33,                      /* READ  */
  YYSYMBOL_READLN = 34,                    /* READLN  */
  YYSYMBOL_THEN = 35,                      /* THEN  */
  YYSYMBOL_TO = 36,                        /* TO  */
  YYSYMBOL_VAR = 37,                       /* VAR  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_WRITE = 39,                     /* WRITE  */
  YYSYMBOL_WRITELN = 40,                   /* WRITELN  */
  YYSYMBOL_LT = 41,                        /* LT  */
  YYSYMBOL_EQUAL = 42,                     /* EQUAL  */
  YYSYMBOL_GT = 43,                        /* GT  */
  YYSYMBOL_ASSIGN = 44,                    /* ASSIGN  */
  YYSYMBOL_LE = 45,                        /* LE  */
  YYSYMBOL_GE = 46,                        /* GE  */
  YYSYMBOL_NE = 47,                        /* NE  */
  YYSYMBOL_LP = 48,                        /* LP  */
  YYSYMBOL_RP = 49,                        /* RP  */
  YYSYMBOL_XID = 50,                       /* XID  */
  YYSYMBOL_XREAL = 51,                     /* XREAL  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* '.'  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '+'  */
  YYSYMBOL_59_ = 59,                       /* '-'  */
  YYSYMBOL_60_ = 60,                       /* '*'  */
  YYSYMBOL_61_ = 61,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_prog = 63,                      /* prog  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_progname = 66,                  /* progname  */
  YYSYMBOL_declist = 67,                   /* declist  */
  YYSYMBOL_dec = 68,                       /* dec  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_standtype = 70,                 /* standtype  */
  YYSYMBOL_arraytype = 71,                 /* arraytype  */
  YYSYMBOL_idlist = 72,                    /* idlist  */
  YYSYMBOL_stmtlist = 73,                  /* stmtlist  */
  YYSYMBOL_stmt = 74,                      /* stmt  */
  YYSYMBOL_assign = 75,                    /* assign  */
  YYSYMBOL_exp = 76,                       /* exp  */
  YYSYMBOL_relop = 77,                     /* relop  */
  YYSYMBOL_simpexp = 78,                   /* simpexp  */
  YYSYMBOL_term = 79,                      /* term  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_read = 81,                      /* read  */
  YYSYMBOL_readfunc = 82,                  /* readfunc  */
  YYSYMBOL_readlist = 83,                  /* readlist  */
  YYSYMBOL_write = 84,                     /* write  */
  YYSYMBOL_writefunc = 85,                 /* writefunc  */
  YYSYMBOL_writelist = 86,                 /* writelist  */
  YYSYMBOL_for = 87,                       /* for  */
  YYSYMBOL_idxexp = 88,                    /* idxexp  */
  YYSYMBOL_varid = 89,                     /* varid  */
  YYSYMBOL_ifstmt = 90,                    /* ifstmt  */
  YYSYMBOL_body = 91                       /* body  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
       2,     2,    60,    58,    57,    59,    53,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    37,    37,    38,    38,    44,    44,    50,    56,    62,
      68,    70,    71,    77,    78,    80,    87,    99,   112,   113,
     115,   116,   117,   118,   120,   122,   147,   172,   177,   183,
     184,   186,   187,   188,   189,   190,   191,   240,   246,   253,
     254,   256,   257,   258,   259,   260,   261,   262,   264,   265,
     324,   398,   399,   472,   547,   548,   549,   550,   551,   552,
     554,   555,   556,   558,   559,   560,   561,   564,   565,   566,
     568,   569,   571,   572,   574,   575,   582,   584,   595,   606,
     612,   618,   619,   625,   631,   632
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DOUBLE", "ID",
  "INTEGER", "REAL", "SINGLE", "STR", "STRING", "INT", "REAL_NUM",
  "ABSOLUTE", "AND", "ARRAY", "BEG", "BREAK", "CASE", "CONST", "CONTINUE",
  "DO", "ELSE", "END", "FOR", "FUNCTION", "IF", "MOD", "NIL", "NOT",
  "OBJECT", "OF", "OR", "PROGRAM", "READ", "READLN", "THEN", "TO", "VAR",
  "WHILE", "WRITE", "WRITELN", "LT", "EQUAL", "GT", "ASSIGN", "LE", "GE",
  "NE", "LP", "RP", "XID", "XREAL", "';'", "'.'", "':'", "'['", "']'",
  "','", "'+'", "'-'", "'*'", "'/'", "$accept", "prog", "$@1", "$@2",
  "progname", "declist", "dec", "type", "standtype", "arraytype", "idlist",
  "stmtlist", "stmt", "assign", "exp", "relop", "simpexp", "term",
  "factor", "read", "readfunc", "readlist", "write", "writefunc",
  "writelist", "for", "idxexp", "varid", "ifstmt", "body", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,   -87,    39,    19,   -87,   -87,   -46,   -87,     8,    50,
      43,    43,   -87,   -87,   -24,   -87,   125,    16,    22,    89,
     274,   274,   274,    44,    31,   118,   -87,   114,   -87,   -87,
     -87,   -87,    35,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     114,    53,    72,    45,    23,   -87,   -87,   -87,   -87,   -87,
      65,   -87,   -87,   -87,    80,   -87,    84,   -87,   -31,   -87,
      86,   139,    98,    28,   -87,    76,   112,   -87,   -87,   -87,
      28,   -87,   215,   -34,   -87,    25,   -87,   138,     1,     6,
      28,    28,    28,   151,   106,   171,    28,   207,   114,   183,
     -87,   -87,    28,   205,    75,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   127,    28,    28,    28,    28,    28,    92,   -87,
     -87,   -37,   -87,   -87,   -87,    26,   -34,   -34,   -34,   113,
     117,   128,    75,   -87,   131,   -87,    48,   183,    96,   -87,
     183,   -34,   -87,   -87,   -87,   -87,   -87,   -87,   -87,    45,
     -87,    28,   -87,   155,   -87,   203,    28,   -87,   183,   -87,
     -87,   -87,   -87,   124,   -87,   229,   -87,   156,   194,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,     0,     0,    11,    12,     3,     1,     0,     0,
       0,     0,    25,    27,     5,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    22,    20,
      21,    23,     0,    17,    18,    19,    16,    15,    26,    28,
       0,    77,     0,     0,     0,    63,    64,    70,    71,    79,
       0,    29,    31,    32,    60,    33,    67,    34,     0,    35,
       0,     0,     0,     0,     7,     0,     0,    58,    55,    56,
       0,    59,     0,    39,    48,    51,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    75,     0,     0,    39,    47,    41,    42,    43,    44,
      45,    46,     0,     0,     0,     0,     0,     0,     8,    30,
      61,     0,    65,    68,    72,     0,    37,    36,    38,     0,
       0,     0,     0,    78,     0,    74,     0,     0,     0,    57,
       0,    40,    49,    50,    52,    53,     9,     2,    62,     0,
      69,     0,     6,     0,     4,     0,     0,    83,     0,    82,
      80,    66,    73,     0,    85,    76,    81,     0,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   178,    64,    91,    34,   -87,
     -87,   -19,   -18,   -87,   -69,   -87,   132,   -75,    -9,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -25,   -87,   -86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     9,    19,     6,    14,    15,    33,    34,    35,
      16,    50,    90,    52,    72,   103,    73,    74,    75,    53,
      54,   111,    55,    56,   115,    57,    65,    76,    59,    91
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    93,    58,   125,   114,    41,     8,    51,    60,    51,
      41,    80,   138,    81,    67,    58,    68,    69,    66,     7,
     139,    62,    51,    82,   104,   105,    12,    41,    18,   132,
     133,    67,    41,    68,    69,    12,    67,    25,    68,    69,
      58,   147,   149,     4,   150,    10,    40,    12,    38,    41,
     110,    49,    58,   112,    86,   113,    49,    71,    58,   109,
      58,     1,   156,    58,    58,   109,   152,   109,    24,   124,
      51,    70,    13,    49,    71,   140,    86,   155,    49,    71,
      41,    13,    26,   141,   146,   106,   107,    11,    26,     5,
      61,    88,     2,    13,    39,    49,    89,   134,   135,    43,
      41,    44,    58,    58,    27,    58,   104,   105,    63,    45,
      46,    88,    36,    37,   151,    47,    48,    77,    41,    43,
      58,    44,    41,    58,   129,    64,    49,   109,    78,    45,
      46,   148,    79,   104,   105,    47,    48,    43,    83,    44,
      42,    43,    41,    44,   136,   137,    49,    45,    46,    84,
      85,    45,    46,    47,    48,    41,    92,    47,    48,   120,
     108,    43,   130,    44,    49,   153,   142,    20,    49,    21,
     143,    45,    46,   119,    43,    41,    44,    47,    48,    22,
     157,   144,    23,   145,    45,    46,   158,    41,    49,    17,
      47,    48,   159,   121,    43,    87,    44,    28,    88,    29,
      30,    49,    94,    31,    45,    46,    43,    41,    44,     0,
      47,    48,   116,   117,   118,     0,    45,    46,   122,     0,
       0,    49,    47,    48,   126,   154,    43,     0,    44,     0,
       0,    95,     0,    49,     0,   131,    45,    46,     0,     0,
     127,    95,    47,    48,     0,     0,    96,    97,    98,     0,
      99,   100,   101,    49,   128,    95,    96,    97,    98,     0,
      99,   100,   101,   123,   102,   104,   105,     0,     0,     0,
      96,    97,    98,     0,    99,   100,   101,    28,     0,    29,
      30,     0,     0,    31,     0,     0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      25,    70,    27,    89,    79,     4,    52,    25,    27,    27,
       4,    42,    49,    44,     8,    40,    10,    11,    43,     0,
      57,    40,    40,    54,    58,    59,     4,     4,    52,   104,
     105,     8,     4,    10,    11,     4,     8,    15,    10,    11,
      65,   127,   128,     4,   130,    37,    15,     4,     4,     4,
      49,    50,    77,    78,    48,    49,    50,    51,    83,    77,
      85,     1,   148,    88,    89,    83,   141,    85,    52,    88,
      88,    48,    50,    50,    51,    49,    48,   146,    50,    51,
       4,    50,    18,    57,    36,    60,    61,    37,    24,    50,
      55,    15,    32,    50,    50,    50,    20,   106,   107,    23,
       4,    25,   127,   128,    15,   130,    58,    59,    55,    33,
      34,    15,    21,    22,   139,    39,    40,    52,     4,    23,
     145,    25,     4,   148,    49,    53,    50,   145,    48,    33,
      34,    35,    48,    58,    59,    39,    40,    23,    52,    25,
      22,    23,     4,    25,    52,    53,    50,    33,    34,    10,
      52,    33,    34,    39,    40,     4,    44,    39,    40,    53,
      22,    23,    35,    25,    50,    10,    53,    42,    50,    44,
      53,    33,    34,    22,    23,     4,    25,    39,    40,    54,
      56,    53,    57,    52,    33,    34,    30,     4,    50,    11,
      39,    40,   158,    22,    23,    63,    25,     3,    15,     5,
       6,    50,    70,     9,    33,    34,    23,     4,    25,    -1,
      39,    40,    80,    81,    82,    -1,    33,    34,    86,    -1,
      -1,    50,    39,    40,    92,    22,    23,    -1,    25,    -1,
      -1,    26,    -1,    50,    -1,   103,    33,    34,    -1,    -1,
      35,    26,    39,    40,    -1,    -1,    41,    42,    43,    -1,
      45,    46,    47,    50,    49,    26,    41,    42,    43,    -1,
      45,    46,    47,    56,    49,    58,    59,    -1,    -1,    -1,
      41,    42,    43,    -1,    45,    46,    47,     3,    -1,     5,
       6,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    32,    63,     4,    50,    66,     0,    52,    64,
      37,    37,     4,    50,    67,    68,    72,    67,    52,    65,
      42,    44,    54,    57,    52,    15,    68,    15,     3,     5,
       6,     9,    14,    69,    70,    71,    69,    69,     4,    50,
      15,     4,    22,    23,    25,    33,    34,    39,    40,    50,
      73,    74,    75,    81,    82,    84,    85,    87,    89,    90,
      73,    55,    73,    55,    53,    88,    89,     8,    10,    11,
      48,    51,    76,    78,    79,    80,    89,    52,    48,    48,
      42,    44,    54,    52,    10,    52,    48,    78,    15,    20,
      74,    91,    44,    76,    78,    26,    41,    42,    43,    45,
      46,    47,    49,    77,    58,    59,    60,    61,    22,    74,
      49,    83,    89,    49,    79,    86,    78,    78,    78,    22,
      53,    22,    78,    56,    73,    91,    78,    35,    49,    49,
      35,    78,    79,    79,    80,    80,    52,    53,    49,    57,
      49,    57,    53,    53,    53,    52,    36,    91,    35,    91,
      91,    89,    79,    10,    22,    76,    91,    56,    30,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    63,    65,    63,    63,    63,    63,
      63,    66,    66,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    71,    72,    72,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    89,    89,    89,
      90,    90,    90,    90,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    11,     0,    11,     0,    11,     9,    10,    11,
       1,     1,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     9,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     4,     1,     1,     1,     3,     1,     3,     4,
       1,     1,     1,     3,     4,     3,     5,     1,     4,     1,
       5,     6,     5,     5,     1,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 3: /* $@1: %empty  */
#line 38 "B103040045.y"
                            {	
		//處理結構中VAR前缺乏;的情況
		char temp[60];
        strcpy(temp, "syntax error, \";\" expected but \"VAR\" found");
        yyerror(temp);
	 }
#line 1729 "y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 44 "B103040045.y"
                                            {
		//處理結構中BEGIN前缺乏;的情況
		char temp[60];
        strcpy(temp, "syntax error, \";\" expected but \"BEGIN\" found");
        yyerror(temp);
	 }
#line 1740 "y.tab.c"
    break;

  case 7: /* prog: PROGRAM progname ';' VAR declist ';' BEG END '.'  */
#line 50 "B103040045.y"
                                                            {
		// no expression here
		char temp[60];
        strcpy(temp, "Note: expected any expressions inside BEGIN-END, but notany");
        yyerror(temp);
	 }
#line 1751 "y.tab.c"
    break;

  case 8: /* prog: PROGRAM progname ';' VAR declist ';' BEG stmtlist ';' END  */
#line 56 "B103040045.y"
                                                                     {	
		//處理結構中END後缺乏.的情況
		char temp[60];
        strcpy(temp, "syntax error, \".\" expected but \"end of file\" found");
        yyerror(temp);
	 }
#line 1762 "y.tab.c"
    break;

  case 9: /* prog: PROGRAM progname ';' VAR declist ';' BEG stmtlist ';' END ';'  */
#line 62 "B103040045.y"
                                                                        {	
		//處理結構中END後不是.卻是;的情況
		char temp[60];
        strcpy(temp, "Syntax error, \".\" expected but \";\" found");
        yyerror(temp);
	 }
#line 1773 "y.tab.c"
    break;

  case 10: /* prog: error  */
#line 68 "B103040045.y"
                 {yyerrok;}
#line 1779 "y.tab.c"
    break;

  case 12: /* progname: XID  */
#line 71 "B103040045.y"
               {
		char temp[50];
		strcpy(temp, "syntax error, identifier's name is too long. ");
		yyerror(temp);
	 }
#line 1789 "y.tab.c"
    break;

  case 15: /* dec: idlist ':' type  */
#line 80 "B103040045.y"
                      {
        for (int i=0;i<idlistCounter;i++){
			strcpy(symtable[idx-1-i].type, (yyvsp[0].str));
			symtable[idx-1-i].undefinedFlag = 0;
		}
		idlistCounter = 0;
    }
#line 1801 "y.tab.c"
    break;

  case 16: /* dec: idlist ASSIGN type  */
#line 87 "B103040045.y"
                         {
		for (int i=0;i<idlistCounter;i++){
			strcpy(symtable[idx-1-i].type, (yyvsp[0].str));
			symtable[idx-1-i].undefinedFlag = 1;
		}
		idlistCounter = 0;

		/* if assignment symbol misuse , report error */
            char temp[60];
            strcpy(temp, "syntax error, \":\" expected but \":=\" found");
            yyerror(temp);
        }
#line 1818 "y.tab.c"
    break;

  case 17: /* dec: idlist EQUAL type  */
#line 99 "B103040045.y"
                            {
		for (int i=0;i<idlistCounter;i++){
			strcpy(symtable[idx-1-i].type, (yyvsp[0].str));
			symtable[idx-1-i].undefinedFlag = 1;
		}
		idlistCounter = 0;
		
		/* if assignment symbol misuse , report error */
            char temp[60];
            strcpy(temp, "syntax error, \"=\" expected but \":=\" found");
            yyerror(temp);
        }
#line 1835 "y.tab.c"
    break;

  case 18: /* type: standtype  */
#line 112 "B103040045.y"
                 {(yyval.str) = (yyvsp[0].str);}
#line 1841 "y.tab.c"
    break;

  case 19: /* type: arraytype  */
#line 113 "B103040045.y"
                     {(yyval.str) = (yyvsp[0].str);}
#line 1847 "y.tab.c"
    break;

  case 20: /* standtype: INTEGER  */
#line 115 "B103040045.y"
                   {(yyval.str) = (yyvsp[0].str);}
#line 1853 "y.tab.c"
    break;

  case 21: /* standtype: REAL  */
#line 116 "B103040045.y"
                {(yyval.str) = (yyvsp[0].str);}
#line 1859 "y.tab.c"
    break;

  case 22: /* standtype: DOUBLE  */
#line 117 "B103040045.y"
                  {(yyval.str) = (yyvsp[0].str);}
#line 1865 "y.tab.c"
    break;

  case 23: /* standtype: STRING  */
#line 118 "B103040045.y"
                  {(yyval.str) = (yyvsp[0].str);}
#line 1871 "y.tab.c"
    break;

  case 24: /* arraytype: ARRAY '[' INT '.' '.' INT ']' OF standtype  */
#line 120 "B103040045.y"
                                                      {(yyval.str) = (yyvsp[0].str);}
#line 1877 "y.tab.c"
    break;

  case 25: /* idlist: ID  */
#line 122 "B103040045.y"
              {

	idlistCounter ++;
	//宣告id，建立table以儲存id與其type對照，並比對是否重複
	/* Store in symbol table */
	/* First, check if there repeat ID encounter */
	int store = 1;
	for (int i=0;i<idx;i++)
	{
		int res = strcmp(symtable[i].name, (yyvsp[0].str));
		if (res == 0) // repetitive ID
		{
			char temp[60];
        	strcpy(temp, "Error: Duplicate identifier ");
			strcat(temp , symtable[i].name);
        	yyerror(temp);
			store = 0;
		}
	}
	if (store)
	{
		strcpy(symtable[idx].name, (yyvsp[0].str));
		idx +=1;
	}
}
#line 1907 "y.tab.c"
    break;

  case 26: /* idlist: idlist ',' ID  */
#line 147 "B103040045.y"
                         {
	
	idlistCounter++;
	/* Store in symbol table */
	/* First, check if there repeat ID encounter */
	int store = 1;
	for (int i=0;i<idx;i++)
	{
		int res = strcmp(symtable[i].name, (yyvsp[0].str));
		if (res == 0) // repetitive ID
		{
			char temp[60];
        	strcpy(temp, "Error: Duplicate identifier ");
			strcat(temp , symtable[i].name);
        	yyerror(temp);
			store = 0;
		}
	}

	if (store)
	{
		strcpy(symtable[idx].name, (yyvsp[0].str));
		idx +=1;
	}
}
#line 1937 "y.tab.c"
    break;

  case 27: /* idlist: XID  */
#line 172 "B103040045.y"
               {
		char temp[50];
		strcpy(temp, "syntax error, identifier's name is too long. ");
		yyerror(temp);
	 }
#line 1947 "y.tab.c"
    break;

  case 28: /* idlist: idlist ',' XID  */
#line 177 "B103040045.y"
                          {
		char temp[50];
		strcpy(temp, "syntax error, identifier's name is too long. ");
		yyerror(temp);
	 }
#line 1957 "y.tab.c"
    break;

  case 36: /* assign: varid ASSIGN simpexp  */
#line 191 "B103040045.y"
                                {

		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[-2].str))==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[0].str))==0)
			{
				chsimp=i;
				break;
			}
		}

		if (chvar!=-1 && symtable[chvar].undefinedFlag){
			char temp[60];
			strcpy(temp, "Error, identifier not found \"");
			strcat(temp, symtable[chvar].name);
			strcat(temp, "\".");
			yyerror(temp);
		}

		if(chvar!=-1 && chsimp!=-1 && (strcmp(symtable[chvar].type, symtable[chsimp].type)!=0)){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[60];
	        	strcpy(temp, "error, incompatible types: got \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" expected \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            	}
		if(chvar!=-1 && chsimp==-1 && (strcmp(symtable[chvar].type, (yyvsp[0].str))!=0)) { 
			// 如果前面是變數後面是常數，且兩個型態不同
				char temp[60];
				strcpy(temp, "error, incompatible types: got \"");
				strcat(temp, symtable[chvar].type);
				strcat(temp, "\" expected \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);
        }
	 }
#line 2011 "y.tab.c"
    break;

  case 37: /* assign: varid EQUAL simpexp  */
#line 240 "B103040045.y"
                               {
		//若符號錯誤，需輸出錯誤訊息
		char temp [50];
		strcpy(temp,"Illegal expression, Use \":=\" to replace the =");
		yyerror(temp);
	 }
#line 2022 "y.tab.c"
    break;

  case 38: /* assign: varid ':' simpexp  */
#line 246 "B103040045.y"
                             {
		//若符號錯誤，需輸出錯誤訊息
		char temp [50];
		strcpy(temp,"Illegal expression, Use \":=\" to replace the :");
		yyerror(temp);
	 }
#line 2033 "y.tab.c"
    break;

  case 48: /* simpexp: term  */
#line 264 "B103040045.y"
                {(yyval.str) = (yyvsp[0].str);}
#line 2039 "y.tab.c"
    break;

  case 49: /* simpexp: simpexp '+' term  */
#line 265 "B103040045.y"
                            {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[-2].str))==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[0].str))==0)
			{
				chsimp=i;
				break;
			}
		}
		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" + \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
        }
		if(chvar==-1 && chsimp!=-1 && strcmp((yyvsp[-2].str), symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, (yyvsp[-2].str));
	        	strcat(temp, "\" + \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, (yyvsp[0].str))) { 
			// 如果前面是變數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, symtable[chvar].type);
				strcat(temp, "\" + \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);  	
        }
		if (chvar==-1 && chsimp==-1 && strcmp((yyvsp[-2].str), (yyvsp[0].str))) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, (yyvsp[-2].str));
				strcat(temp, "\" + \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
	 }
#line 2103 "y.tab.c"
    break;

  case 50: /* simpexp: simpexp '-' term  */
#line 324 "B103040045.y"
                            {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)	//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[-2].str))==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)	//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[0].str))==0)
			{
				chsimp=i;
				break;
			}
		}
		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" + \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
        }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, (yyvsp[0].str))) { 
			// 如果前面是變數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, symtable[chvar].type);
				strcat(temp, "\" + \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);  	
        }
		if (chvar==-1 && chsimp==-1 && strcmp((yyvsp[-2].str), (yyvsp[0].str))) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, (yyvsp[-2].str));
				strcat(temp, "\" - \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
		if(chvar==-1 && chsimp!=-1 && strcmp((yyvsp[-2].str), symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, (yyvsp[-2].str));
	        	strcat(temp, "\" - \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar!=-1 && strcmp(symtable[chvar].type, "string") == 0){
			// if both operator are string type when 2 variable

			if (chsimp != -1 && (strcmp(symtable[chsimp].type, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" - \"String\"");
				yyerror(temp);
			}
			else if (chsimp == -1 && (strcmp((yyvsp[0].str), "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" - \"String\"");
				yyerror(temp);
			}
		}
	 }
#line 2181 "y.tab.c"
    break;

  case 52: /* term: factor '*' factor  */
#line 399 "B103040045.y"
                             {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[-2].str))==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)	//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[0].str))==0)
			{
				chsimp=i;
				break;
			}
		}
		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" * \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, (yyvsp[0].str))) { 
			// 如果前面是變數後面是常數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, (yyvsp[0].str));
	        	strcat(temp, "\" * \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar==-1 && chsimp==-1 && strcmp((yyvsp[-2].str), (yyvsp[0].str))) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, (yyvsp[-2].str));
				strcat(temp, "\" * \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
		if(chvar==-1 && chsimp!=-1 && strcmp((yyvsp[-2].str), symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, (yyvsp[-2].str));
	        	strcat(temp, "\" * \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
			if (chvar!=-1 && strcmp(symtable[chvar].type, "string") == 0){
			// if both operator are string type when 2 variable

			if (chsimp != -1 && (strcmp(symtable[chsimp].type, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" * \"String\"");
				yyerror(temp);
			}
			else if (chsimp == -1 && (strcmp((yyvsp[0].str), "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" * \"String\"");
				yyerror(temp);
			}
		}
	 }
#line 2259 "y.tab.c"
    break;

  case 53: /* term: factor '/' factor  */
#line 472 "B103040045.y"
                             {
		int chvar=-1,chsimp=-1;
		for (int i=0;i<idx;i++)//檢查左值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[-2].str))==0)
			{
				chvar=i;
				break;
			}
		}
		for (int i=0;i<idx;i++)//檢查右值是否在table中，若有是第幾個
		{
			if(strcmp(symtable[i].name, (yyvsp[0].str))==0)
			{
				chsimp=i;
				break;
			}
		}

		if(chvar!=-1 && chsimp!=-1 && strcmp(symtable[chvar].type, symtable[chsimp].type)!=0){ 
			// 如果前後都是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\" / \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if(chvar!=-1 && chsimp==-1 && strcmp(symtable[chvar].type, (yyvsp[0].str))) { 
			// 如果前面是變數後面是常數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, (yyvsp[0].str));
	        	strcat(temp, "\" / \"");
	        	strcat(temp, symtable[chvar].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar==-1 && chsimp==-1 && strcmp((yyvsp[-2].str), (yyvsp[0].str))) { 
			// 如果前面是常數後面是常數，且兩個型態不同
				char temp[53];
				strcpy(temp, "error: Operator is not overloaded: \"");
				strcat(temp, (yyvsp[-2].str));
				strcat(temp, "\" / \"");
				strcat(temp, (yyvsp[0].str));
				strcat(temp, "\"");
				yyerror(temp);  	
        } 
		if(chvar==-1 && chsimp!=-1 && strcmp((yyvsp[-2].str), symtable[chsimp].type)!=0) { 
			// 如果前面是常數後面是變數，且兩個型態不同
	        	char temp[53];
	        	strcpy(temp, "error: Operator is not overloaded: \"");
	        	strcat(temp, (yyvsp[-2].str));
	        	strcat(temp, "\" / \"");
	        	strcat(temp, symtable[chsimp].type);
	        	strcat(temp, "\"");
	        	yyerror(temp);
            }
		if (chvar!=-1 && strcmp(symtable[chvar].type, "string") == 0){
			// if both operator are string type when 2 variable

			if (chsimp != -1 && (strcmp(symtable[chsimp].type, "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" / \"String\"");
				yyerror(temp);
			}
			else if (chsimp == -1 && (strcmp((yyvsp[0].str), "string")==0)){
				char temp[53];
				strcpy(temp, "Operator is not overloaded: \"String\" / \"String\"");
				yyerror(temp);
			}
		}
	 }
#line 2338 "y.tab.c"
    break;

  case 54: /* factor: varid  */
#line 547 "B103040045.y"
                 {(yyval.str) = (yyvsp[0].str);}
#line 2344 "y.tab.c"
    break;

  case 55: /* factor: INT  */
#line 548 "B103040045.y"
               {(yyval.str) = "integer";}
#line 2350 "y.tab.c"
    break;

  case 56: /* factor: REAL_NUM  */
#line 549 "B103040045.y"
                    {(yyval.str) = "real";}
#line 2356 "y.tab.c"
    break;

  case 57: /* factor: LP simpexp RP  */
#line 550 "B103040045.y"
                         {(yyval.str) = (yyvsp[-1].str);}
#line 2362 "y.tab.c"
    break;

  case 58: /* factor: STR  */
#line 551 "B103040045.y"
               {(yyval.str) = "string";}
#line 2368 "y.tab.c"
    break;

  case 59: /* factor: XREAL  */
#line 552 "B103040045.y"
                 {(yyval.str) = "real"; yyerror("syntax error: Invalid REAL number used, please check again.");}
#line 2374 "y.tab.c"
    break;

  case 75: /* for: FOR idxexp body  */
#line 575 "B103040045.y"
                           {
		// lack of DO keywords
		char temp[60];
		strcpy(temp, "Syntax error, \"DO\" expected, please add DO keywords.");
		yyerror(temp);
	 }
#line 2385 "y.tab.c"
    break;

  case 77: /* varid: ID  */
#line 584 "B103040045.y"
              {
	//變數，如果不存在則編寫錯誤訊息
		if(!check((yyvsp[0].str)))
		{
			char temp[46];
            strcpy(temp, "error, identifier not found \"");
        	strcat(temp, (yyvsp[0].str));
            strcat(temp, "\"");
            yyerror(temp);
		}
	 }
#line 2401 "y.tab.c"
    break;

  case 78: /* varid: ID '[' simpexp ']'  */
#line 595 "B103040045.y"
                              {
		//陣列，如果不存在則編寫錯誤訊息
		if(!check((yyvsp[-3].str)))
		{
			char temp[46];
            strcpy(temp, "error, identifier not found \"");
            strcat(temp, (yyvsp[-3].str));
            strcat(temp, "\"");
            yyerror(temp);
		}
	 }
#line 2417 "y.tab.c"
    break;

  case 79: /* varid: XID  */
#line 606 "B103040045.y"
              {
		char temp[54];
        strcpy(temp, "syntax error, identifier's name is too long. ");
        yyerror(temp);
	 }
#line 2427 "y.tab.c"
    break;

  case 80: /* ifstmt: IF exp RP THEN body  */
#line 612 "B103040045.y"
                            {
		//缺少左括號的情況，編寫錯誤訊息, but shift/reduce occured
				char temp[100];
            	strcpy(temp, "syntax error, \"THEN\" expected but \")\" found");
            	yyerror(temp);
	 }
#line 2438 "y.tab.c"
    break;

  case 82: /* ifstmt: IF LP exp RP body  */
#line 619 "B103040045.y"
                            {
		//缺少THEN的情況，編寫錯誤訊息
				char temp[60];
            	strcpy(temp, "syntax error, \"THEN\" expected but \"identifier \" found");
            	yyerror(temp);
	 }
#line 2449 "y.tab.c"
    break;

  case 83: /* ifstmt: IF LP exp THEN body  */
#line 625 "B103040045.y"
                               {//缺少右括號的情況，編寫錯誤訊息
				char temp[100];
            	strcpy(temp, "syntax error, \")\" expected but \"THEN\" found");
            	yyerror(temp);
	 }
#line 2459 "y.tab.c"
    break;


#line 2463 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 634 "B103040045.y"


int main() {
	yyparse();
	return 0;
}
// print Error message
void yyerror(const char *error) {
	printf("\rLine %u: %s\n", line_num, error);
	flag =0;
}
static char check(const char *id) { // 如果id存在回傳1，反之回傳0
	for(int i = 0; i <idx; ++i)
		if(!strcmp(symtable[i].name, id))
			return 1;
	return 0;
}
