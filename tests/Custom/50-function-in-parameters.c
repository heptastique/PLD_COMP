int32_t test(int32_t a)
{
    putchar(a);
    int32_t b;
    b = a + 1;
    return b;
}

void main()
{
    int32_t a;
    a = 39;
    a = test(a+1);
    putchar(a-2);
    a = 40;
    putchar(test(a - 1) + 1);
}