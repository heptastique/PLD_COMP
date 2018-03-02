#!/bin/bash
CLASSPATH="./../antlr/antlr-4.7.1-complete.jar:."
exec java -jar ./../antlr/antlr-4.7.1-complete.jar "$@"