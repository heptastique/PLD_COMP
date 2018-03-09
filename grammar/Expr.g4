grammar Expr;
prog: expr ;
expr: expr '*' expr # mult
    | expr '/' expr # div
    | expr '+' expr # add
    | expr '-' expr # moins
    |   INT         # const
    |  '(' expr ')' # par
    ;
INT     : [0-9]+ ;

