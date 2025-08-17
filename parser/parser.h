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

#ifndef YY_YY_PARSER_PARSER_H_INCLUDED
# define YY_YY_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    ASSERT_ = 258,                 /* ASSERT_  */
    IF_ = 259,                     /* IF_  */
    THEN = 260,                    /* THEN  */
    ELSE_ = 261,                   /* ELSE_  */
    LET = 262,                     /* LET  */
    IN = 263,                      /* IN  */
    WITH = 264,                    /* WITH  */
    OR_ = 265,                     /* OR_  */
    REC = 266,                     /* REC  */
    INHERIT = 267,                 /* INHERIT  */
    ELLIPSIS = 268,                /* ELLIPSIS  */
    INTERP = 269,                  /* INTERP  */
    SPACE = 270,                   /* SPACE  */
    COMMENT = 271,                 /* COMMENT  */
    II = 272,                      /* II  */
    URI = 273,                     /* URI  */
    PATH = 274,                    /* PATH  */
    FLOAT = 275,                   /* FLOAT  */
    INT_ = 276,                    /* INT_  */
    T_ID = 277,                    /* T_ID  */
    TEXT = 278,                    /* TEXT  */
    ARG_ID = 279,                  /* ARG_ID  */
    ARG_BRACKET = 280,             /* ARG_BRACKET  */
    IMPL = 281,                    /* IMPL  */
    OR = 282,                      /* OR  */
    AND = 283,                     /* AND  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    LEQ = 286,                     /* LEQ  */
    GEQ = 287,                     /* GEQ  */
    UPDATE = 288,                  /* UPDATE  */
    CONCAT = 289,                  /* CONCAT  */
    NEGATE = 290                   /* NEGATE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser/parser.y"

    int token;
    Node* node;

#line 104 "parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void** ast_root, void* scanner);


#endif /* !YY_YY_PARSER_PARSER_H_INCLUDED  */
