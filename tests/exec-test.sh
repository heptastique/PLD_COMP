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

../bin/app Custom/51-factorial.c -o > ./target/output
assert "./target/prog.out" "("

../bin/app Demo/5.1.1-Void-Programm.c -o > ./target/output
assert "./target/prog.out" ""

../bin/app Demo/5.2.1-int32-Declaration.c -o > ./target/output
assert "./target/prog.out" ""

../bin/app Demo/5.2.2-int32-Declarations.c -o > ./target/output
assert "./target/prog.out" ""

../bin/app Demo/5.2.3-int32-char-Declarations.c -o > ./target/output
assert "./target/prog.out" ""

../bin/app Demo/5.2.4-char-mult.c -o > ./target/output
assert "./target/prog.out" "OK\n"

../bin/app Demo/5.3.1-putchar.c -o > ./target/output
assert "./target/prog.out" "OK "

../bin/app Demo/5.4.4-Variables-putchar-Affectations.c -o > ./target/output
assert "./target/prog.out" "OK\n"

../bin/app Demo/5.5.1-Expressions.c -o > ./target/output
assert "./target/prog.out" "OP\n"

../bin/app Demo/5.6.1-int-If-Else.c -o > ./target/output
assert "./target/prog.out" "V\n"

../bin/app Demo/5.6.2-Variable-If-Else.c -o > ./target/output
assert "./target/prog.out" "V\n"

../bin/app Demo/5.7.1-int-While.c -o > ./target/output
assert "./target/prog.out" "VVVVV\n"

../bin/app Demo/5.8.1-char-Value-Return.c -o > ./target/output
assert "./target/prog.out" "a"

../bin/app Demo/5.8.2-Variable-Value-Return.c -o > ./target/output
assert "./target/prog.out" "a"

../bin/app Demo/5.8.2-putchar-Value-Return.c -o > ./target/output
assert "./target/prog.out" "a"

../bin/app Demo/5.11-Function-Call.c -o > ./target/output
assert "./target/prog.out" "((()"

../bin/app Demo/5.13-Factorial-Complex-Program.c -o > ./target/output
assert "./target/prog.out" "("

../bin/app Demo/5.15-6Parameters-Function-Call.c -o > ./target/output
assert "./target/prog.out" "-"

assert_end examples
