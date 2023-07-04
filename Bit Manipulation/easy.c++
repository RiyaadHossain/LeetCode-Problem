/* 231. Power of Two */
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return (n & n - 1) == 0;
}

/* GFG: Check whether K-th bit is set or not */
bool checkKthBit(int n, int k)
{
    return n & (1 << k);
}

/* GFG: Odd or Even */
string oddEven(int N)
{
    if ((N & 1) == 0)
    {
        return "even";
    }

    return "odd";
}

/* 231. Power of Two */
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return (n & n - 1) == 0;
}

/* GFG: Set the rightmost unset bit */
int setBit(int N)
{
    int result = N;
    int mask = 1;

    while (mask <= N)
    {
        if (!(N & mask))
        {
            result = N | mask;
            break;
        }

        mask <<= 1;
    }

    return result;
}

/* GFG: Swap two numbers */
pair<int, int> get(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    pair<int, int> resultPair = {a, b};
    return resultPair;
}
