grammar Prog;

prog: include* decl* fun+                   # Lprog;

fun: typeretour Name '(' params ')' bloc    # Lfun;

instr: init									# LinstrInit
	| decl                                  # LinstrDecl
	| affectation							# LinstAffectation
    | appelfonct ';'                        # LinstAppelfonct
    | retourfonct    						# LinstRetourfonct
    | insif									# LinstIf
    | inswhile								# LinsWhile
    | expr ';'                      		# LinstExpr
    ;

init: type initParams (',' initParams)* ';' # Linit;

decl: type declParams (',' declParams)* ';' # Ldecl;

affectation: varleftpart (',' varleftpart)* operation expr (',' expr)* ';'	# Laffectation;

appelfonct: Name '(' valeurs ')'            # Lappelfonct;

valeurs: variable (',' variable)*           # Lvaleurs
        | /* epsilon */                     # LvaleursEpsilon
        ;

variable: prepostop varleftpart             # Lvariablevarleftpartpre
        | varleftpart prepostop             # Lvariablevarleftpartpos
        | varleftpart                       # Lvariablevarleftpart
        | Entier                            # LvariableEntier
        | Caractere                         # LvariableCaractere
        ;

varleftpart: Name '[' expr ']'				# LvarleftpartTable
			| Name							# Lvarleftpart
			;
			     
expr: variable								# LexprVariable
    | appelfonct                            # LexprAppelfonction
    | expr operationbinaire expr            # LexprOperationbinaire
    | operationunaire expr                  # LexprOperationunaire
    | '(' expr ')'                          # LexprParentheses
    ;

params: 'void'                              # LparamsVoid
        | param (',' param)*                # Lparams
        | /* epsilon */                     # LparamsEpsilon
        ;

param: type Name '[' Entier? ']'			# LparamTable
	| type Name                         	# Lparam
	;

declParams: Name '[' Entier ']'				# LdeclparamTable
			| Name                     		# Ldeclparam
			;
			
initParams: Name '[' Entier? ']' ('=' '{' valeurs '}')? # LinitparamTable
		| Name ('=' expr)? 								# Linitparam
		;

typeretour: 'void'                          # LtyperetourVoid
            | type                          # Ltype
            ;

type: 'char'                                # Lchar
    | 'int32_t'                             # Lint32_t
    | 'int64_t'                             # Lint64_t
    ;
    
bloc: '{' instr* '}'                        # Lbloc;

insif: 'if' '(' expr ')' bloc inselse?		# Lif;

inselse: 'else' bloc						# Lelse;

inswhile: 'while' '(' expr ')' bloc			# Lwhile;

retourfonct: 'return' expr ';'              # Lretourfonct;

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

prepostop: '++'								# LprepostopInc
			| '--'							# LprepostopDec
			;
				
include: '#include' '<' Includename '>'		# LincludeSys
		| '#include' '"' Includename '"'	# LincludeCustom
		;

Name: [a-zA-Z][a-zA-Z0-9]*;

Includename: [a-zA-Z][a-zA-Z0-9]*[.]?[a-zA-Z0-9]*;

Entier: [0-9]+;

Caractere: '\'' ~['\\] '\'';

WS: [ \t\n\r]+ -> skip;
