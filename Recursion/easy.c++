/* 50. Pow(x, n) */
double myPow(double x, int n)
{
    // Base Case
    if (n == 0)
        return 1;

    // If 'n' is negative
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }

    // Calculate Power
    if (n % 2 == 0)
    {
        return myPow(x * x, n / 2);
    }
    else
    {
        return x * myPow(x, n - 1);
    }
}
