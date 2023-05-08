%{
    #include "node.h"
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
    NVariableDeclaration *var_decl;
    NFunctionDeclaration *func_decl;
    std::vector<NVariableDeclaration*> *varvec;
    std::vector<NExpression*> *exprvec;
    std::string *string;
    std::vector<NArgDeclaration*> *arg_type_vec;
    std::vector<NArgument*> *arg_name_vec;
    int token;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TFLOAT TINTEGER TSTRING 
%token <token> TTYPE_STRING TTYPE_INT TTYPE_FLOAT TTYPE_VOID
%token <token> TEQUAL TNOT TCEQ TCNE TCLT TCLE TCGT TCGE
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE
%token <token> TDOT TCOMMA TPLUS TMINUS TMUL TDIV
%token <token> TINC TDEC TADD_ASSIGN TSUB_ASSIGN TMUL_ASSIGN TDIV_ASSIGN TMOD_ASSIGN
%token <token> TAND TOR
%token <token> TDOUBLE_COLON TSEMICOLON TARROW
%token <token> TSYM_PRINT TSYM_READ TSYM_IF TSYM_ELSE TSYM_WHILE  
%token <token> TSYM_FN TSYM_CALL TSYM_RESULT TSYM_GUARD

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident arg_name
%type <expr> expr factor_var rel_expr term factor
%type <arg_type_vec> func_decl_args
%type <arg_name_vec> func_arg_name
%type <exprvec> call_args
%type <block> program stmts block func_stmts func_block
%type <stmt> stmt var_decl print while_stmt if_stmt func_stmt var_assign 
%type <stmt> arg_decl func_assign func_decl 
%type <token> var_type assign_op rel_expr_op expr_op term_op unary_op

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
stmt :
      /*Empty statement*/ { $$ = new NEmpty(); }
      | var_assign TSEMICOLON
      | var_decl TSEMICOLON
      | print TSEMICOLON
      | while_stmt
      | while_stmt TSEMICOLON
      | if_stmt
      | if_stmt TSEMICOLON
      | func_decl
      | func_decl TSEMICOLON
      | func_assign
      | func_assign TSEMICOLON
      ;

assign_op : TADD_ASSIGN | TSUB_ASSIGN | TMUL_ASSIGN 
          | TDIV_ASSIGN | TMOD_ASSIGN | TINC | TDEC
          ;

var_type : TTYPE_INT | TTYPE_FLOAT | TTYPE_STRING
         ;

var_decl : ident ident { $$ = new NVariableDeclaration(*$1, *$2); }
         | ident ident TEQUAL expr { $$ = new NVariableDeclaration(*$1, *$2, $4); }
         ;

var_assign : ident TEQUAL rel_expr { $$ = new NAssignment(*$<ident>1, *$3); }
           | ident assign_op rel_expr { $$ = new NAssignment(*$<ident>1, $2, *$3); }
           ;

print : TSYM_PRINT TLPAREN rel_expr TRPAREN { $$ = new NPrint(*$3); }
      ;

while_stmt : TSYM_WHILE rel_expr block { $$ = new NWhile(*$2, *$3); }
           ;

if_stmt : TSYM_IF rel_expr block { $$ = new NIfStatement(*$2, *$3); } 
        | TSYM_IF rel_expr block TSYM_ELSE block { $$ = new NIfStatement(*$2, *$3, *$5); }
        ;


/* Expression */
rel_expr : expr 
         | expr rel_expr_op expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
         ;

expr : term
     | term expr_op term { $$ = new NBinaryOperator(*$1, $2, *$3); }
     ;

term : factor
     | factor term_op factor { $$ = new NBinaryOperator(*$1, $2, *$3); }

factor : unary_op factor { $$ = new NUnaryOperator($1, *$2); }
       | factor_var
       | ident { $<ident>$ = $1; }
       | TLPAREN rel_expr TRPAREN { $$ = $2; }
       | TSYM_READ TLPAREN TRPAREN { $$ = new NRead(); }
       | TSYM_CALL ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$2, *$4); delete $4; }
       ;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
      ;

rel_expr_op : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE | TDOT
        ;

expr_op : TPLUS | TMINUS | TOR
        ;

term_op : TMUL | TDIV | TAND
        ;

unary_op : TNOT | TMINUS | TPLUS
         ;

factor_var : TINTEGER { $$ = new NInteger(atol($1->c_str())); delete $1;}
           | TFLOAT { $$ = new NFloat(atof($1->c_str())); delete $1;}
           | TSTRING { $$ = new NString(*$1); delete $1; }
           ;

/* Function */
func_block : TLBRACE func_stmts TRBRACE { $$ = $2; }
           | TLBRACE TRBRACE { $$ = new NBlock(); }
           ;
        
func_stmts : func_stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
      | func_stmts func_stmt { $1->statements.push_back($<stmt>2); }
      ;

func_stmt : stmt 
          | TSYM_RESULT TSEMICOLON { $$ = new NResult(); }
          | TSYM_RESULT TARROW rel_expr TSEMICOLON { $$ = new NResult(*$3); }
          | TSYM_GUARD rel_expr TSEMICOLON { $$ = new NGuard(*$2); }
          | TSYM_GUARD rel_expr TARROW rel_expr TSEMICOLON { $$ = new NGuard(*$2, *$4); }
          ;

call_args : /*blank (void)*/  { $$ = new ExpressionList(); }
          | rel_expr { $$ = new ExpressionList(); $$->push_back($1); }
          | call_args TCOMMA rel_expr  { $1->push_back($3); }
          ;

arg_decl : var_type { $$ = new NArgDeclaration(*$1); }
         | arg_decl TCOMMA var_type { $$ = new NArgDeclaration(*$3); }
         ;


func_decl_args : arg_decl { $$ = new ArgTypeList(); $$->push_back($<arg_decl>1); }
               | func_decl_args TCOMMA arg_decl { $1->push_back($<arg_decl>3); }
               ;
        
func_decl : TSYM_FN ident TDOUBLE_COLON func_decl_args TARROW var_type 
            { $$ = new NFunctionDeclaration(*$2, *$4, *$6); delete $4; }
          | TSYM_FN ident TDOUBLE_COLON func_decl_args TARROW TTYPE_VOID 
            { $$ = new NFunctionDeclaration(*$2, *$4); delete $4; }
          | TSYM_FN ident TDOUBLE_COLON TARROW var_type 
            { $$ = new NFunctionDeclaration(*$2, *$5); }
          | TSYM_FN ident TDOUBLE_COLON TARROW TTYPE_VOID 
            { $$ = new NFunctionDeclaration(*$2); }
          ;

arg_name : ident { $$ = new NArgument(*$1); }
         ;

func_arg_name : arg_name { $$ = new ArgList(); $$->push_back($<arg_name>1); }
              | func_arg_name TCOMMA arg_name { $1->push_back($<arg_name>3); }
              ;

func_assign : TSYM_FN ident TEQUAL func_block { $$ = new NFunctionAssignment(*$2, *$4); }
            | TSYM_FN ident TLPAREN TRPAREN TEQUAL func_block { $$ = new NFunctionAssignment(*$2, *$6); }
            | TSYM_FN ident func_arg_name TEQUAL func_block { $$ = new NFunctionAssignment(*$2, *$3, *$5); delete $3;}
            | TSYM_FN ident TLPAREN func_arg_name TRPAREN TEQUAL func_block { $$ = new NFunctionAssignment(*$2, *$4, *$7); delete $4;}
            ; 
    

%%
