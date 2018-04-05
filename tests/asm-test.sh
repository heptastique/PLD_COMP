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

../bin/app Front/ValidPrograms/05_OperatorDiv.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/05_OperatorDiv.s"

../bin/app Front/ValidPrograms/06_OperatorMult.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/06_OperatorMult.s"

../bin/app Front/ValidPrograms/13_OperatorMod.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/13_OperatorMod.s"

../bin/app Front/ValidPrograms/13_OperatorMod.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/13_OperatorMod.s"

../bin/app Front/ValidPrograms/16_OperatorBOr.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/16_OperatorBOr.s"

../bin/app Front/ValidPrograms/17_OperatorBAnd.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/17_OperatorBAnd.s"

../bin/app Front/ValidPrograms/18_OperatorNeg.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/18_OperatorNeg.s"

../bin/app Front/ValidPrograms/19_OperatorLeftShift.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/19_OperatorLeftShift.s"

../bin/app Front/ValidPrograms/20_OperatorRightShift.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/20_OperatorRightShift.s"

../bin/app Front/ValidPrograms/25_OperatorNot.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/25_OperatorNot.s"

../bin/app Front/ValidPrograms/26_OperatorXor.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/26_OperatorXor.s"

../bin/app Front/ValidPrograms/27_OperatorComp.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/27_OperatorComp.s"

../bin/app Front/ValidPrograms/50_CharConst.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/50_CharConst.s"

../bin/app Front/ValidPrograms/51_CharConstSpecial.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Front/51_CharConstSpecial.s"

# Given Back tests

../bin/app Back/1_decls.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Back/1_decls.s"

../bin/app Back/1_empty.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/Back/1_empty.s"

assert_end examples
