grammar Prog;

prog: include* decl* fun+                       # Lprog;

fun: typeretour Name '(' params ')' bloc        # Lfun;

instr: decl                                     # LinstrDecl
    | init                                      # LinstrInit
    | affectation                               # LinstAffectation
    | appelfonct ';'                            # LinstAppelfonct
    | retourfonct                               # LinstRetourfonct
    | insif                                     # LinstIf
    | inswhile                                  # LinsWhile
    | expr ';'                                  # LinstExpr
    ;

decl: type declParams (',' declParams)* ';'     # Ldecl;

init: type initParams (',' initParams)* ';'     # Linit;

affectation: varleftpart (',' varleftpart)* operation expr (',' expr)* ';'      # Laffectation;

appelfonct: Name '(' valeurs ')'                # Lappelfonct;

valeurs: expr (',' expr)*                       # Lvaleurs
        | /* epsilon */                         # LvaleursEpsilon
        ;

variable: prepostop varleftpart                 # Lvariablevarleftpartpre
        | varleftpart prepostop                 # Lvariablevarleftpartpos
        | varleftpart                           # Lvariablevarleftpart
        | Entier                                # LvariableEntier
        | Caractere                             # LvariableCaractere
        ;

varleftpart: Name '[' expr ']'                  # LvarleftpartTable
            | Name                              # Lvarleftpart
            ;

expr:  expr operationbinairetest expr2           # LexprOperationbinaireTest
    | expr2                                      # StandardCasesExpr3
    ;
expr2: expr2 operationbinaire expr3             # LexprOperationbinaire
    | expr3                                     # StandardCasesExpr2
    ;
expr3: expr3 operationbinairemultdiv expr3      # LexprOperationbinairemultdiv
    | '(' expr ')'                              # LexprParentheses
    | variable                                  # LexprVariable
    | appelfonct                                # LexprAppelfonction
    | operationunaire expr3                     # LexprOperationunaire
    ;

params: 'void'                                  # LparamsVoid
        | param (',' param)*                    # Lparams
        | /* epsilon */                         # LparamsEpsilon
        ;

param: type Name '[' Entier? ']'                # LparamTable
        | type Name                             # Lparam
        ;

declParams: Name '[' Entier ']'                 # LdeclparamTable
        | Name                                  # Ldeclparam
        ;
                        
initParams: Name '[' Entier? ']' ('=' '{' valeurs '}')?         # LinitparamTable
        | Name '=' expr                 # Linitparam
        | Name                          # LinitparamDecl
        ;

typeretour: 'void'                          # LtyperetourVoid
        | type                              # Ltype
        ;

type: 'char'                                # Lchar
    | 'int32_t'                             # Lint32_t
    | 'int64_t'                             # Lint64_t
    ;
    
bloc: '{' instr* '}'                        # Lbloc;

insif: 'if' '(' expr ')' bloc inselse?      # Lif;

inselse: 'else' bloc                        # Lelse;

inswhile: 'while' '(' expr ')' bloc         # Lwhile;

insfor: 'for' '(' forpartone? ';' forparttwo? ';' forpartthree? ')' bloc    # Lfor;

retourfonct: 'return' expr ';'              # Lretourfonct;

forpartone: decl                            # LforpartoneDecl
        | init                              # LforpartoneInit
        | affectation                       # LforpartoneAffectation
        | expr                              # LforpartoneExpr
        ;

forparttwo: type Name '=' expr              # LforparttwoInit
        | affectation                       # LforparttwoAffectation
        | expr                              # LforparttwoExpr
        ;

forpartthree: affectation                   # LforpartthreeAffectation
        | expr                              # LforpartthreeExpr
        ;

operation: '='                              # LoperationEqual
            | '+='                          # LoperationPlusequal
            | '-='                          # LoperationMoinsequal
            | '*='                          # LoperationMultequal
            | '/='                          # LoperationDivequal
            | '%='                          # LoperationModequal
            | '^='                          # LoperationXorbitwise
            | '&='                          # LoperationAndbitwise
            | '|='                          # LoperationOrbitwise
            | '<<='                         # LoperationLeftshiftbitwise
            | '>>='                         # LoperationRightshiftbitwise
            ;

operationunaire: '-'                        # LoperationunaireMoins
                | '~'                       # LoperationunaireNot
                ;

operationbinairetest: '=='                      # LoperationbinaireEqual
                | '!='                      # LoperationbinaireNotequal
                | '<'                       # LoperationbinaireLt
                | '>'                       # LoperationbinaireGt
                | '<='                      # LoperationbinaireLte
                | '>='                      # LoperationbinaireGte
                | '&&'                      # LoperationbinaireAnd
                | '||'                      # LoperationbinaireOr
                ;
operationbinaire : '+'                       # LoperationbinairePlus
                   | '-'                       # LoperationbinaireMoins
                   | '&'                       # LoperationbinaireAndbitwise
                   | '|'                       # LoperationbinaireOrbitwise
                   | '<<'                      # LoperationbinaireLeftshiftbiwise
                   | '>>'                      # LoperationbinaireRightshiftbitwise
                   | '^'                       # LoperationbinaireXorbitwise
                   ;

operationbinairemultdiv: '*'                       # LoperationbinaireMult
              | '/'                       # LoperationbinaireDiv
              | '%'                       # LoperationbinaireMod
              ;

prepostop: '++'                             # LprepostopInc
        | '--'                              # LprepostopDec
        ;
                                
include: '#include' '<' Includename '>'     # LincludeSys
                | '#include' '"' Includename '"'    # LincludeCustom
                ;

Name: [a-zA-Z][a-zA-Z0-9]*;

Includename: [a-zA-Z][a-zA-Z0-9]*[.]?[a-zA-Z0-9]*;

Entier: [0-9]+;

Caractere: '\''('\\'['"?abfnrtv\\]|.|)'\'';

WS: [ \t\n\r]+ -> skip;
