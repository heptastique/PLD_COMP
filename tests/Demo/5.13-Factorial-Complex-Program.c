int32_t factorial(int32_t n)
{
    int32_t ret;

    if (n < 1)
    {
        return 1;
    }
    else
    {
        ret = n * factorial(n - 1);
        return ret;
    }
}

void main()
{
    putchar(factorial(3) + 34);
}
