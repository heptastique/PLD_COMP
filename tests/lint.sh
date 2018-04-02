#!/bin/bash

if [ "${TRAVIS_PULL_REQUEST}" != "false" ]; then
    lintspaces -n -b -l 1 -d spaces -s 4 -i 'js-comments' ../src/** ../main.cpp ../grammar/prog.g4
    if [ $? = 0 ]; then
        echo "All files pass linting"
    else
        exit 1
    fi
else
    echo "Linting only on pull requests builds"
fi
