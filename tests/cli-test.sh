#!/bin/bash
. lib/assert.sh

# Set up distinct target folder
rm -rf target target2
mkdir -p target target2

# Assert manually specified path for generated asm works
../bin/app Custom/01-simple-func.c -Sout target2/test.s > ./target/output
assert "ls target2" "test.s"

# Assert executable is generated to default path with -o
../bin/app Custom/01-simple-func.c -o > ./target/output
assert "ls target" "output\nprog.out\nprog.s"

# Assert executable is generated to specified path
../bin/app Custom/01-simple-func.c -oout target2/test.out -Sout target2/test.s > ./target/output
assert "ls target2" "test.out\ntest.s"

# Clean up after tests
rm -rf target2

assert_end examples
