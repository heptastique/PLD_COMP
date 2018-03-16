grammar Prog;

prog: decl* fun                             # Lprog;

fun: typeretour Name '(' params ')' bloc    # Lfun;

params: 'void'                              # LparamsVoid
        | param (',' param)*                # Lparams
        | /* epsilon */                     # LparamsEpsilon
        ;

param: type Name                            # Lparam;

bloc: '{' (instr*)? '}'                     # Lbloc;

instr: decl                                 # LinstrDecl;

typeretour: 'void'                         # LtyperetourVoid
            | type                      # Ltype
            ;

type: 'char'                                # Lchar
    | 'int32_t'                             # Lint32_t
    | 'int64_t'                             # Lint64_t
    ;

decl : type Name ';'                    # Ldecl;

Name : [a-zA-Z][a-zA-Z0-9]*; 



WS: [ \t\n\r]+ -> skip;