int32_t test(int32_t a)
{
    int32_t b;
    b = a + 1;
    return b;
}

void main()
{
    int32_t a;
    int32_t b;
    b = 40;
    a = test(20) * 2;
    putchar(a);
    a = 1 + test(40);
    putchar(a);
    a = 1 + test(b);
    putchar(a);
    a = test(b) + 1;
    putchar(a);
}