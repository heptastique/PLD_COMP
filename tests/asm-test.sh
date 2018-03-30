#!/bin/bash
. lib/assert.sh

## Prepare test environment
mkdir -p target

## Begin tests
# How to test :
# ../bin/app <File to test> > ./target/output
# assert_file "cat ./target/prog.s" "<Path to expected generated file>"

../bin/app Custom/01-simple-func.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/00-basic.s"

../bin/app Front/ValidPrograms/01_SimpleDeclaration.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/01-simpleDeclaration.s"

../bin/app Custom/27-putchar.c > ./target/output
assert_file "cat ./target/prog.s" "./ASM/02-putchar.s"

## Clean up after tests
rm -rf target

assert_end examples