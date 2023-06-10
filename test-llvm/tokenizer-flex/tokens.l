%{
#include <string>
#include "../node.hpp"
#include "../parser-bison/parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { return 1; }
%}

%%

[ \t\n]              ; /* ignore whitespace */
Int                     return TOKEN(TTYPE_INT);
let                     return TOKEN(TLET);
if                      return TOKEN(TIF);
else                    return TOKEN(TELSE);
[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*          SAVE_TOKEN; return TFLOAT;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
":"                     return TOKEN(TCOLON);
"&&"                    return TOKEN(TAND);
"||"                    return TOKEN(TOR);
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
"="                     return TOKEN(TEQUAL);
";"                     return TOKEN(TSEMICOLON);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
"!"                     return TOKEN(TNOT);
<<EOF>>                 printf("End of File \n"); yyterminate();
.                       printf("Unknown token: %s \n", yytext); yyterminate();

%%
