void function(int32_t x, char a)
{
	int32_t y;
	y = x;
	
	char b;
	b = a;
	
	putchar(a);
	putchar(b);
	
	b = a + 1;
	
	putchar(a);
	putchar(b);
}

void main()
{
	int32_t y;
	y = 40;
	
	char b;
	b = '(';
	
	function(y, b);
}
