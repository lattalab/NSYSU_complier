/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 173 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
