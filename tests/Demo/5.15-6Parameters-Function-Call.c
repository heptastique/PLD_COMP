void function(char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
	char x;
	
	x = a + b + c + d + e;
	x = x + f + g + h + i;
	
	putchar(x);
} 

void main()
{
	function(1, 2, 3, 4, 5, 6, 7, 8, 9);
}
