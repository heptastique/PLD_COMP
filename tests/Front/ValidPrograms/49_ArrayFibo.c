#include <stdint.h>

void main() {
   int32_t a[10];
   int32_t i;
   a[0] = 1;
   a[1] = 1;
   for (i=2;i<10;i=i+1) {
      a[i] = a[i-1] + a[i-2];
   }
}
