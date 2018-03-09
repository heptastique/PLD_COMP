#include <stdint.h>

int32_t function(int32_t a[], int32_t n) {
   int32_t i;
   int32_t result;
   result = 0;
   for (i=0;i<n;i=i+1) {
      result = result+a[i];
   }
   return result;
}
   
void main() {
   int32_t a[10];
   int32_t i;
   int32_t r;
   for (i=0;i<10;i=i+1) {
      a[i] = i;
   }
   r = function(a,10);
}
