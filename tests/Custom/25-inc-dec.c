#include "test.h"

void main() {
    char a;
    ++a;
    --a;
    a++;
    a--;
    a[++a];
    test(--a);
    a = ++a;
}
void test(char a){

}