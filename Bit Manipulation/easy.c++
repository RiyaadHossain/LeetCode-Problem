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

/* GFG: Exceptionally odd */
int getOddOccurrence(int arr[], int n)
{
    int oddOccurrence = 0;

    for (int i = 0; i < n; i++)
        oddOccurrence = oddOccurrence ^ arr[i];

    return oddOccurrence;
}

/* 2220. Minimum Bit Flips to Convert Number */
int minBitFlips(int start, int goal)
{
    int count = 0;

    long long diffBits = start ^ goal;
    while (diffBits != 0)
    {
        if (diffBits & 1)
            count++;
        diffBits >>= 1;
    }

    return count;
}

/* GFG: Two numbers with odd occurrences */
vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    // Step 1 - Find xorr of 1 - N
    int xorr = 0;
    for (int i = 0; i < N; i++)
        xorr = xorr ^ Arr[i];

    // Step 2 - Find where the first bit differ
    int tempX = xorr;
    int diffBitIndex = 0;
    while (tempX)
    {
        if (tempX & 1)
            break;
        diffBitIndex++;
        tempX >>= 1;
    }

    // Step 3 - Separte all the element into two parts (based on the differ bit) [xorr1 and xorr2]
    int xorr1 = 0;
    int xorr2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] & (1 << diffBitIndex))
            xorr1 = xorr1 ^ Arr[i];
        else
            xorr2 = xorr2 ^ Arr[i];
    }

    // Step 4 - firstInt = xorr ^ xorr1; secondInt = xorr ^ xorr2;
    int firstInt = xorr ^ xorr2;
    int secondInt = xorr ^ xorr1;

    vector<long long int> result;
    if (firstInt > secondInt)
        result = {firstInt, secondInt};
    else
        result = {secondInt, firstInt};

    return result;
}