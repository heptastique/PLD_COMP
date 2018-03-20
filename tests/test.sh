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

# Given tests

assert "../bin/app Front/ValidPrograms/01_SimpleDeclaration.c" "Programme:\n Fonction: Name=main TypeRetour=0\n     Bloc:\n      Instruction: Declaration: Name=a Type=3\n\n\nOk"

# end of test suite
assert_end examples