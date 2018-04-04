#!/bin/bash
. lib/assert.sh


assert_raises "../bin/app Front/SemanticError/01_MissingVarDeclaration.c" 104
assert_raises "../bin/app Front/SemanticError/02_GlobalDeclarationWithSameName.c" 103
assert_raises "../bin/app Front/SemanticError/03_FunctionParametersWithSameName.c" 102
assert_raises "../bin/app Front/SemanticError/05_FunctionsSameName.c" 105
assert_raises "../bin/app Front/SemanticError/04_BlocDeclarationWithSameName.c" 101
assert_raises "../bin/app Front/SemanticError/06_FunctionDoesNotExist.c" 106
assert_raises "../bin/app Front/SemanticError/07_MissingVarDeclarationInIf.c" 104
assert_raises "../bin/app Front/SemanticError/08_MissingVarDeclarationInElse.c" 104
assert_raises "../bin/app Front/SemanticError/09_MissingVarDeclarationInWhile.c" 104

assert_end examples