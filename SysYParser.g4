parser grammar SysYParser;

options {
    tokenVocab = SysYLexer;
}

compUnit
    : (decl|funcDef)+ ;

decl
    : constDecl 
    | varDecl
    | exp SEMICOLON; 


constDecl
    : CONST bType constDef (COMMA constDef)* SEMICOLON;

bType
    : INT
    | FLOAT;

constDef
    : IDENT (L_BRACKT constExp R_BRACKT)* ASSIGN constInitVal;

constInitVal
    : constExp  
    | L_BRACE (constInitVal (COMMA constInitVal)*)? R_BRACE 
    ;

varDecl
    : bType varDef (COMMA varDef)* SEMICOLON;

varDef
    : IDENT (L_BRACKT constExp R_BRACKT)* 
    | IDENT (L_BRACKT constExp R_BRACKT)* ASSIGN initVal 
    ;

initVal 
    : exp 
    | L_BRACE (initVal (COMMA initVal)*)?  R_BRACE 
    ;
            
funcDef
    : funcType funcName L_PAREN funcFparams? R_PAREN block;

funcName
    : IDENT;

funcType: VOID | INT;

funcFparams
    : funcFparam (COMMA funcFparam)*;

funcFparam
    : bType IDENT (L_BRACKT R_BRACKT(L_BRACKT exp R_BRACKT)*)?;

block
    : L_BRACE blockItem* R_BRACE;

blockItem
    : decl
    | stmt;

stmt
    : lVal ASSIGN exp SEMICOLON 
    | exp?  SEMICOLON 
    | block 
    | IF L_PAREN cond R_PAREN stmt (ELSE stmt)? 
    | WHILE L_PAREN cond R_PAREN stmt
    | BREAK SEMICOLON 
    | CONTINUE SEMICOLON 
    | RETURN exp? SEMICOLON 
    ;

exp
   : unaryOp exp                            #Exp_Unary
   | exp op=(MUL | DIV | MOD) exp           #Exp_MulDivMod
   | exp op=(PLUS | MINUS) exp              #Exp_PlusMinus
   | number                                 #Exp_Num
   | funcName L_PAREN funcRparams? R_PAREN  #Exp_Func
   | lVal                                   #Exp_lVal                 
   | L_PAREN exp R_PAREN                    #Exp_Paren
   ;

cond
   : exp                                #Cond_Exp 
   | cond op=(LT | GT | LE | GE) cond   #Cond_Compare
   | cond op=(EQ | NEQ) cond            #Cond_Eq
   | cond AND cond                      #Cond_And 
   | cond OR cond                       #Cond_Or
   ;

lVal
    : IDENT (L_BRACKT exp R_BRACKT)*;

number
    : INTEGER_CONST
    ;

unaryOp
    : PLUS
    | MINUS
    | NOT;

funcRparams
   : exp (COMMA exp)*
   ;

constExp
   : exp
   ;