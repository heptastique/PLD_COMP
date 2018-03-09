#include<inttypes.h>
void main(void){
	char i;
	i='A';
	
	while(i<'Z'+1)	{
			putchar(i);
			i=i+1;
		} 
	putchar('\n');
}
