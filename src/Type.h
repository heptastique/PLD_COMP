#pragma once

#include <string>

enum Type {
    VOID = 0,
    INT32_T = 1,
    INT64_T = 2,
    CHAR = 3,
    ERROR = -1
};

enum TypeVariable {
    NAME = 0,
    ENTIER = 1,
    CARACTERE = 2,
};

enum Operateur {
    EQUAL = 0,
    PLUSEQUAL = 1,
    MINUSEQUAL = 2,
    MULTEQUAL = 3,
    DIVEQUAL = 4,
    MODEQUAL = 5,
    XORBITWISE = 6,
    ANDBITWISE = 7,
    ORBITWISE = 8,
    LESTSHIFTBITWISE = 9,
    RIGHTSHIFTBITWISE = 10,
    MINUSU = 11,
    NOT = 12,
    PLUS = 13,
    MINUS = 14,
    MULT = 15,
    DIV = 16,
    MOD = 17,
    EQUALEQUAL = 18,
    NOTEQUAL = 19,
    LT = 20,
    GT = 21,
    LTE = 22,
    GTE = 23,
    AND = 24,
    OR = 25,
    ANDBB = 26,
    ORBB = 27,
    LEFTSHIFTBITWISEB = 28,
    RIGHTSHIFTBITWISEB = 29,
    XORBITWISEB = 30
};
