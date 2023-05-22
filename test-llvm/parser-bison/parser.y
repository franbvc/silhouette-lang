%{
    #include "../node.hpp"
    NBlock *programBlock; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %sn", s); }
%}

/* Represents the many different ways we can access our data */
%union {
    Node *node;
    NBlock *block;
    NExpression *expr;
    NStatement *stmt;
    int token;
    std::string *string;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TINTEGER TFLOAT
%token <token> TLPAREN TRPAREN
%token <token> TPLUS TMINUS TMUL TDIV
%token <token> TSEMICOLON

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <expr> expr factor_var term factor
%type <block> program stmts
%type <stmt> stmt
%type <token> expr_op term_op

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : stmts { programBlock = $1; }
        ;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

/* Statement */
stmt : expr { $$ = new NExpressionStatement(*$1); };

/* Expression */
expr : term
     | term expr_op term { $$ = new NBinaryOperator(*$1, $2, *$3); }
     ;

term : factor
     | factor term_op factor { $$ = new NBinaryOperator(*$1, $2, *$3); }

factor : factor_var
       | TLPAREN expr TRPAREN { $$ = $2; }
       ;

expr_op : TPLUS | TMINUS
        ;

term_op : TMUL | TDIV
        ;

factor_var : TINTEGER { $$ = new NInteger(atol($1->c_str())); delete $1; }
	   | TFLOAT { $$ = new NFloat(atof($1->c_str())); delete $1; }
           ;

%%
