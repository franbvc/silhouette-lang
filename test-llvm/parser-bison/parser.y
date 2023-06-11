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
    NIdentifier *ident;
    int token;
    std::string *string;
    NVariableDeclaration *var_decl;
    std::vector<NVariableDeclaration*> *varvec;
    std::vector<NExpression*> *exprvec;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TINTEGER TFLOAT
%token <token> TTYPE_INT
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE
%token <token> TIF TELSE
%token <token> TPLUS TMINUS TMUL TDIV TEQUAL
%token <token> TNOT TCEQ TCNE TCGT TCGE TCLT TCLE
%token <token> TAND TOR
%token <token> TSEMICOLON TCOLON TARROW TCOMMA
%token <token> TLET TFN TCALL TRESULT

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <expr> expr factor_var term factor rel_expr
%type <varvec> fn_decl_args
%type <exprvec> fn_call_args
%type <block> program stmts block fn_block fn_stmts
%type <stmt> stmt var_decl if_stmt var_assign fn_decl fn_var_decl
%type <stmt> fn_stmt
%type <token> var_type

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : stmts { programBlock = $1; }
        ;

block : TLBRACE stmts TRBRACE { $$ = $2; }
      | TLBRACE TRBRACE { $$ = new NBlock(); }
      ;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

/* Statement */
stmt : rel_expr TSEMICOLON { $$ = new NExpressionStatement(*$1); }
     | var_decl TSEMICOLON
     | var_assign TSEMICOLON
     | fn_decl
     | if_stmt
     ;

var_decl : TLET ident TCOLON var_type { $$ = new NVariableDeclaration(*$2, $4); }
         | TLET ident TCOLON var_type TEQUAL rel_expr { $$ = new NVariableDeclaration(*$2, $4, $6); }
         ;

var_type : TTYPE_INT;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }

var_assign : ident TEQUAL rel_expr { $$ = new NAssignment(*$<ident>1, *$3); };

if_stmt : TIF rel_expr block { $$ = new NIfStatement(*$2, *$3, *(new NBlock())); }
        | TIF rel_expr block TELSE block { $$ = new NIfStatement(*$2, *$3, *$5); }
        ;

/* Function */
/* fn addTwo a, b = { result -> a + b }; */
fn_block : TLBRACE fn_stmts TRBRACE { $$ = $2; };

fn_stmts : fn_stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
	 | fn_stmts fn_stmt { $1->statements.push_back($<stmt>2); }
	 ;

fn_stmt : stmt
	| TRESULT TARROW rel_expr TSEMICOLON { $$ = new NResult(*$3); }
	;

fn_decl : TFN ident fn_decl_args TEQUAL fn_block
	{ $$ = new NFunctionDeclaration(*$2, *$3, *$5); delete $3; }
	;

fn_decl_args : /*blank*/  { $$ = new VariableList(); }
        | fn_var_decl { $$ = new VariableList(); $$->push_back($<var_decl>1); }
        | fn_decl_args TCOMMA fn_var_decl { $1->push_back($<var_decl>3); }
        ;

fn_var_decl : ident TCOLON  var_type { $$ = new NVariableDeclaration(*$1, $3); }
	    ;

fn_call_args : /*blank*/ { $$ = new ExpressionList(); }
	     | rel_expr { $$ = new ExpressionList(); $$->push_back($1); }
	     | fn_call_args TCOMMA rel_expr { $1->push_back($3); }
	     ;

/* Expression */
rel_expr : rel_expr TCEQ expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
	 | rel_expr TCNE expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
	 | rel_expr TCGT expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
	 | rel_expr TCGE expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
	 | rel_expr TCLT expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
	 | rel_expr TCLE expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
	 | expr
	 ;

expr : expr TPLUS term { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | expr TMINUS term { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | expr TOR term { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | term
     ;

term : term TMUL factor { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | term TDIV factor { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | term TAND factor { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | factor
     ;

factor : TLPAREN rel_expr TRPAREN { $$ = $2; }
       | TPLUS factor { $$ = new NUnaryOperator($1, *$2); }
       | TMINUS factor { $$ = new NUnaryOperator($1, *$2); }
       | TNOT factor { $$ = new NUnaryOperator($1, *$2); }
       | ident { $<ident>$ = $1; }
       | TCALL ident TLPAREN fn_call_args TRPAREN { $$ = new NMethodCall(*$2, *$4); delete $4; }
       | factor_var
       ;

factor_var : TINTEGER { $$ = new NInteger(atol($1->c_str())); delete $1; }
	   //| TFLOAT { $$ = new NFloat(atof($1->c_str())); delete $1; }
           ;

%%
