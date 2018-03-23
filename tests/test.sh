#!/bin/bash
. lib/assert.sh

# How to test
# assert "<command>" "<expected command output>"

# Custom tests

assert "../bin/app Custom/01-simple-func.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/03-decl-func.c" "Programme:\n Declaration: Name=a Type=3\n Fonction: Name=main TypeRetour=0\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/04-multiple-decl.c" "Programme:\n Declaration: Name=a Type=3\n Declaration: Name=b Type=3\n Fonction: Name=main TypeRetour=0\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/06-simple-decl-func-bloc.c" "Programme:\n Declaration: Name=a Type=3\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=b Type=3\n\n\nOk"
assert "../bin/app Custom/07-simple-decl-func-bloc-mult.c" "Programme:\n Declaration: Name=a Type=3\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=b Type=3\n      Instruction: Declaration: Name=i Type=1\n\n\nOk"
assert "../bin/app Custom/08-simple-func-param.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Param:\n      Declaration: Name=n Type=3\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/09-simple-func-mult-param.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Param:\n      Declaration: Name=n Type=3\n      Declaration: Name=i Type=1\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/10-decl-func-param-bloc.c" "Programme:\n Declaration: Name=a Type=3\n Declaration: Name=leInt Type=2\n Fonction: Name=main TypeRetour=0\n     Param:\n      Declaration: Name=c Type=3\n      Declaration: Name=oint Type=1\n      Declaration: Name=bigInt Type=2\n     Bloc:\n      Instruction: Declaration: Name=b Type=3\n      Instruction: Declaration: Name=i Type=1\n\n\nOk"
assert "../bin/app Custom/11-multiple-func.c" "Programme:\n Fonction: Name=test1 TypeRetour=0\n     Bloc:\n\n Fonction: Name=main TypeRetour=0\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/12-return-int32.c" "Programme:\n Fonction: Name=func TypeRetour=1\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/13-return-int64.c" "Programme:\n Fonction: Name=func TypeRetour=2\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/14-return-char.c" "Programme:\n Fonction: Name=func TypeRetour=3\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/15-function-call.c" "Programme:\n Declaration: Name=n Type=3\n Fonction: Name=main TypeRetour=2\n     Param:\n      Declaration: Name=n Type=3\n     Bloc:\n      Instruction: Declaration: Name=n Type=3\n      Instruction: AppelFunction: Name=test\n\n\nOk"
assert "../bin/app Custom/16-function-call-params.c" "Programme:\n Fonction: Name=main TypeRetour=1\n     Bloc:\n      Instruction: AppelFunction: Name=func1 Variable: Type=2 Valeur='a' \n      Instruction: AppelFunction: Name=func2 Variable: Type=0 Valeur=name \n      Instruction: AppelFunction: Name=func3 Variable: Type=0 Valeur=name  Variable: Type=1 Valeur=4 \n\n\nOk"
assert "../bin/app Custom/17-retour-name.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: RetourFonction: Expression: Variable: Type=0 Valeur=name \n\n\nOk"
assert "../bin/app Custom/18-retour-entier.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: RetourFonction: Expression: Variable: Type=1 Valeur=8 \n\n\nOk"
assert "../bin/app Custom/19-retour-caractere.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: RetourFonction: Expression: Variable: Type=2 Valeur='a' \n\n\nOk"
assert "../bin/app Custom/20-affectation-simple.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=a Type=1\n      Instruction: Affectation:  Variable: Type=0 Valeur=a  Operateur=0 Expression: Variable: Type=1 Valeur=1 \n\n\nOk"
assert "../bin/app Custom/21-affectation-variable.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=a Type=1\n      Instruction: Declaration: Name=b Type=1\n      Instruction: Affectation:  Variable: Type=0 Valeur=a  Operateur=0 Expression: Variable: Type=0 Valeur=b \n      Instruction: Affectation:  Variable: Type=0 Valeur=a  Operateur=0 Expression: Variable: Type=2 Valeur='c' \n\n\nOk"

# Given tests

assert "../bin/app Front/ValidPrograms/01_SimpleDeclaration.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=a Type=3\n\n\nOk"
assert "../bin/app Front/ValidPrograms/02_IncludeStdint.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=a Type=1\n\n\nOk"

# end of test suite
assert_end examples