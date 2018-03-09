#include <stdint.h>

int32_t function(int32_t a) {
   return a+1;
}
   
void main() {
   int32_t a;
   a = 1;
   a = function(a);
}
