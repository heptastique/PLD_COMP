#!/bin/bash
. lib/assert.sh

# How to test
# assert "<command>" "<expected command output>"

assert "../bin/app Custom/01-simple-func.c" "Programme:\n Fonction: Name=main\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/03-decl-func.c" "Programme:\n Declaration: Name=a Type=3\n Fonction: Name=main\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/04-multiple-decl.c" "Programme:\n Declaration: Name=a Type=3\n Declaration: Name=b Type=3\n Fonction: Name=main\n     Bloc:\n\n\nOk"
assert "../bin/app Custom/05-simple-func-bloc.c" "Programme:\n Fonction: Name=main\n     Bloc:\n     Instruction: Declaration: Name=a Type=3\n\n\nOk"
assert "../bin/app Custom/06-simple-decl-func-bloc.c" "Programme:\n Declaration: Name=a Type=3\n Fonction: Name=main\n     Bloc:\n     Instruction: Declaration: Name=b Type=3\n\n\nOk"

# end of test suite
assert_end examples