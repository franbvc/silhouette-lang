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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    TIDENTIFIER = 258,             /* TIDENTIFIER  */
    TFLOAT = 259,                  /* TFLOAT  */
    TINTEGER = 260,                /* TINTEGER  */
    TSTRING = 261,                 /* TSTRING  */
    TTYPE_STRING = 262,            /* TTYPE_STRING  */
    TTYPE_INT = 263,               /* TTYPE_INT  */
    TTYPE_FLOAT = 264,             /* TTYPE_FLOAT  */
    TTYPE_VOID = 265,              /* TTYPE_VOID  */
    TEQUAL = 266,                  /* TEQUAL  */
    TNOT = 267,                    /* TNOT  */
    TCEQ = 268,                    /* TCEQ  */
    TCNE = 269,                    /* TCNE  */
    TCLT = 270,                    /* TCLT  */
    TCLE = 271,                    /* TCLE  */
    TCGT = 272,                    /* TCGT  */
    TCGE = 273,                    /* TCGE  */
    TLPAREN = 274,                 /* TLPAREN  */
    TRPAREN = 275,                 /* TRPAREN  */
    TLBRACE = 276,                 /* TLBRACE  */
    TRBRACE = 277,                 /* TRBRACE  */
    TDOT = 278,                    /* TDOT  */
    TCOMMA = 279,                  /* TCOMMA  */
    TPLUS = 280,                   /* TPLUS  */
    TMINUS = 281,                  /* TMINUS  */
    TMUL = 282,                    /* TMUL  */
    TDIV = 283,                    /* TDIV  */
    TINC = 284,                    /* TINC  */
    TDEC = 285,                    /* TDEC  */
    TADD_ASSIGN = 286,             /* TADD_ASSIGN  */
    TSUB_ASSIGN = 287,             /* TSUB_ASSIGN  */
    TMUL_ASSIGN = 288,             /* TMUL_ASSIGN  */
    TDIV_ASSIGN = 289,             /* TDIV_ASSIGN  */
    TMOD_ASSIGN = 290,             /* TMOD_ASSIGN  */
    TAND = 291,                    /* TAND  */
    TOR = 292,                     /* TOR  */
    TDOUBLE_COLON = 293,           /* TDOUBLE_COLON  */
    TSEMICOLON = 294,              /* TSEMICOLON  */
    TARROW = 295,                  /* TARROW  */
    TSYM_PRINT = 296,              /* TSYM_PRINT  */
    TSYM_READ = 297,               /* TSYM_READ  */
    TSYM_IF = 298,                 /* TSYM_IF  */
    TSYM_ELSE = 299,               /* TSYM_ELSE  */
    TSYM_WHILE = 300,              /* TSYM_WHILE  */
    TSYM_FN = 301,                 /* TSYM_FN  */
    TSYM_CALL = 302,               /* TSYM_CALL  */
    TSYM_RESULT = 303,             /* TSYM_RESULT  */
    TSYM_GUARD = 304               /* TSYM_GUARD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "parser.y"

    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    NIdentifier *ident;
    NVariableDeclaration *var_decl;
    NFunctionDeclaration *func_decl;
    std::vector<NVariableDeclaration*> *varvec;
    std::vector<NExpression*> *exprvec;
    std::string *string;
    std::vector<NArgDeclaration*> *arg_type_vec;
    std::vector<NArgument*> *arg_name_vec;
    int token;

#line 129 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
