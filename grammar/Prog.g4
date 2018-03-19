grammar Prog;

prog: decl* init* fun*                      # Lprog;

fun: typeretour Name '(' params ')' bloc    # Lfun;

params: 'void'                              # LparamsVoid
        | param (',' param)*                # Lparams
        | /* epsilon */                     # LparamsEpsilon
        ;

param: type Name                            # Lparam;

bloc: '{' instr* '}'                        # Lbloc;

instr: decl                                 # LinstrDecl
    | appelfonct                            # LinstAppelfonct
    | retourfonct                           # LinstRetourfonct
    ;

typeretour: 'void'                          # LtyperetourVoid
            | type                          # Ltype
            ;

type: 'char'                                # Lchar
    | 'int32_t'                             # Lint32_t
    | 'int64_t'                             # Lint64_t
    ;

decl: type Name '[' ']' ';'                 # LdeclTable
    | type Name ';'                         # Ldecl
    ;

appelfonct: Name '(' valeurs ')'            # Lappelfonct;

retourfonct: 'return' variable ';'          # Lretourfonct;

init: type Name '[' param ']' ';'           # LinitTable
    | type Name '=' param ','               # Linit
    ;

valeurs: variable (',' variable)*           # Lvaleurs
        | /* epsilon */                     # LvaleursEpsilon
        ;

variable: Name                              # LvariableName
        | Entier                            # LvariableEntier
        | Caractere                         # LvariableCaractere
        ;

Name: [a-zA-Z][a-zA-Z0-9]*;

Entier: [0-9]+;

Caractere: . ;

WS: [ \t\n\r]+ -> skip;