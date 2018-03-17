#!/bin/bash
. lib/assert.sh

# How to test
# assert "<command>" "<expected command output>"

assert "../bin/app Custom/01-simple.c" "Programme:\n Declaration: Name=unChar Type=3\n Fonction: Name=main\n     Bloc:\n\n\nOk"

# end of test suite
assert_end examples