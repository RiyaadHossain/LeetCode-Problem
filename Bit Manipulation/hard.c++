/* Coding Ninja: Count total set bits */
int maxPowerOf2(int num)
{
    int ans = 0;
    while (1 << ans <= num)
    {
        ans++;
    }

    return ans - 1;
}

int countNoOfSetBits(int num)
{

    // Base Case
    if (num <= 0)
        return 0;

    // Helper Func: To get largest power of num
    int power = maxPowerOf2(num);

    int bitTill2x = (1 << (power - 1)) * power;
    int singleBitFrom2xToNum = num - (1 << power) + 1;
    int remainingBit = countNoOfSetBits(num - (1 << power));

    return bitTill2x + singleBitFrom2xToNum + remainingBit;
}