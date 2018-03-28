#include "test.h"

void main() {
    ++a;
    --a;
    a++;
    a--;
    a[++a];
    test(--a);
    a = ++a;
}