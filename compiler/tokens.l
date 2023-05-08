%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { }
%}

%%

[ \t\n]              ; /* ignore whitespace */    
print                   { return TOKEN(TSYM_PRINT); }
read                    { return TOKEN(TSYM_READ); }
if                      { return TOKEN(TSYM_IF); }
else                    { return TOKEN(TSYM_ELSE); }
while                   { return TOKEN(TSYM_WHILE); }
result                  { return TOKEN(TSYM_RESULT); }
guard                   { return TOKEN(TSYM_GUARD); }
fn                      { return TOKEN(TSYM_FN); }
call                    { return TOKEN(TSYM_CALL); }
void                    { return TOKEN(TTYPE_VOID); }
str                     { return TOKEN(TTYPE_STRING); }
int                     { return TOKEN(TTYPE_INT); }
float                   { return TOKEN(TTYPE_FLOAT); }        
[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*          SAVE_TOKEN; return TFLOAT;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
\"([^\\\n\r"]|(\\.))*\" SAVE_TOKEN; return TSTRING;
"="                     return TOKEN(TEQUAL);
"!"                     return TOKEN(TNOT);
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
"."                     return TOKEN(TDOT);
","                     return TOKEN(TCOMMA);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
"++"                    return TOKEN(TINC);
"--"                    return TOKEN(TDEC);
"+="                    return TOKEN(TADD_ASSIGN);
"-="                    return TOKEN(TSUB_ASSIGN);
"*="                    return TOKEN(TMULT_ASSIGN);
"/="                    return TOKEN(TDIV_ASSIGN);
"%="                    return TOKEN(TMOD_ASSIGN);
"&&"                    return TOKEN(TAND);
"||"                    return TOKEN(TOR);
"::"                    return TOKEN(TDOUBLE_COLON);
";"                     return TOKEN(TSEMICOLON)
"->"                    return TOKEN(TARROW);    
.                       printf("Unknown token!n"); yyterminate();

%%
