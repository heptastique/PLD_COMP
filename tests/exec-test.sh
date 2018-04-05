#!/bin/bash
. lib/assert.sh

../bin/app Back/2_putchar.c -o > ./target/output
assert "./target/prog.out" "OK "

../bin/app Back/3_variables.c -o > ./target/output
assert "./target/prog.out" "OK\n"

../bin/app Back/4-VarConstAddCall.c -o > ./target/output
assert "./target/prog.out" "OP\n"

../bin/app Custom/48-function-putchar.c -o > ./target/output
assert "./target/prog.out" "OKP"

../bin/app Custom/49-multi-operation-function.c -o > ./target/output
assert "./target/prog.out" "****"

../bin/app Custom/50-function-in-parameters.c -o > ./target/output
assert "./target/prog.out" "('')"

assert_end examples
