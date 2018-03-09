#!/bin/bash
. lib/assert.sh

assert "../bin/app Custom/simple-expr" "5"
assert "../bin/app Custom/big-expr" "20"

# end of test suite
assert_end examples