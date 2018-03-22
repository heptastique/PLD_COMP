#!/bin/bash
. lib/assert.sh

mkdir -p target

../bin/app Custom/01-simple-func.c > output

assert_file "cat ./target/prog.s" "./ASM/00-basic.s"

assert_end examples