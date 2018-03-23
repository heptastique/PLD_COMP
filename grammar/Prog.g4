grammar Prog;

prog: include* decl* fun+                   # Lprog;

fun: typeretour Name '(' params ')' bloc    # Lfun;

params: 'void'                              # LparamsVoid
        | param (',' param)*                # Lparams
        | /* epsilon */                     # LparamsEpsilon
        ;

param: type Name                            # Lparam;

bloc: '{' instr* '}'                        # Lbloc;

instr: decl                                 # LinstrDecl
	| affectation							# LinstAffectation
    | appelfonct                            # LinstAppelfonct
    | retourfonct                           # LinstRetourfonct
    ;

affectation: varleftpart operation expr ';'	# Laffectation;

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

appelfonct: Name '(' valeurs ')' ';'        # Lappelfonct;

retourfonct: 'return' expr ';'              # Lretourfonct;

valeurs: variable (',' variable)*           # Lvaleurs
        | /* epsilon */                     # LvaleursEpsilon
        ;

expr: variable								# LexprVariable
    | appelfonct                            # LexprAppelfonction
    | expr operationbinaire expr            # LexprOperationbinaire
    | operationunaire expr                  # LexprOperationunaire
    | '(' expr ')'                          # LexprParentheses
    ;

variable: varleftpart						# Lvariablevarleftpart
        | Entier                            # LvariableEntier
        | Caractere                         # LvariableCaractere
        ;

varleftpart: Name '[' expr ']'				# LvarleftpartTable
			| Name							# Lvarleftpart
			;
	
operation: '='								# LoperationEqual
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

operationunaire: '-'						# LoperationunaireMoins
                | '~'                       # LoperationunaireNot
                ;

operationbinaire: '+'						# LoperationbinairePlus
                | '-'                       # LoperationbinaireMoins
                | '*'                       # LoperationbinaireMult
                | '/'                       # LoperationbinaireDiv
                | '%'                       # LoperationbinaireMod
                | '=='                      # LoperationbinaireEqual
                | '!='                      # LoperationbinaireNotequal
                | '<'                       # LoperationbinaireLt
                | '>'                       # LoperationbinaireGt
                | '<='                      # LoperationbinaireLte
                | '>='                      # LoperationbinaireGte
                | '&&'                      # LoperationbinaireAnd
                | '||'                      # LoperationbinaireOr
                | '&'                       # LoperationbinaireAndbitwise
                | '|'                       # LoperationbinaireOrbitwise
                | '<<'                      # LoperationbinaireLeftshiftbiwise
                | '>>'                      # LoperationbinaireRightshiftbitwise
                | '^'                       # LoperationbinaireXorbitwise
                ;         

include: '#include' '<' Includename '>'		# LincludeSys
		| '#include' '"' Includename '"'	# LincludeCustom
		;

Name: [a-zA-Z][a-zA-Z0-9]*;

Includename: [a-zA-Z][a-zA-Z0-9]*[.]?[a-zA-Z0-9]*;

Entier: [0-9]+;

Caractere: '\'' ~['] '\'';

WS: [ \t\n\r]+ -> skip;
