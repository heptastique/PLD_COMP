#!/bin/bash
. lib/assert.sh

## Prepare test environment
mkdir -p target

## Begin tests
# How to test :
# ../bin/app <File to test> > ./target/output
# assert_file "cat ./target/prog.s" "<Path to expected generated file>"

../bin/app Custom/01-simple-func.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Custom/01-simple-func.s"

../bin/app Front/ValidPrograms/01_SimpleDeclaration.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/01_SimpleDeclaration.s"

../bin/app Custom/27-putchar.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Custom/27-putchar.s"

../bin/app Custom/11-multiple-func.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Custom/11-multiple-func.s"

../bin/app Front/ValidPrograms/03_OperatorPlus.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/03_OperatorPlus.s"

../bin/app Front/ValidPrograms/04_OperatorMinus.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/04_OperatorMinus.s"

../bin/app Front/ValidPrograms/50_CharConst.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/50_CharConst.s"

../bin/app Front/ValidPrograms/51_CharConstSpecial.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/51_CharConstSpecial.s"

assert_end examples
