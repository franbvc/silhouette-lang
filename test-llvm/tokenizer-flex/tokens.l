%{
#include <string>
#include "../node.hpp"
#include "../parser-bison/parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { }
%}

%%

[ \t\n]              ; /* ignore whitespace */
[0-9]+                  SAVE_TOKEN; return TINTEGER;
";"                     return TOKEN(TSEMICOLON);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);

.                       printf("Unknown token: %s \n", yytext); yyterminate();

%%
