char test(char a, char b)
{
    a = 'O';
    b = 'K';
    putchar(a);
    putchar(b);
    return a + 1;
}

void main(){
    char a;
    char b;
    a = test(b,b);
    putchar(a);
}
