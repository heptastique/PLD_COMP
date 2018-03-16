#!/bin/bash
. lib/assert.sh

# How to test
# assert "<command>" "<expected command output>"

assert "../bin/app Custom/simple-expr" "5"
assert "../bin/app Custom/big-expr" "20"

# end of test suite
assert_end examples