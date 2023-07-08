/* 29. Divide Two Integers */
int divide(int dividend, int divisor)
{
    long long n = dividend;
    long long m = divisor;

    int sign = (n < 0) ^ (m < 0) == 0 ? 1 : -1;

    n = abs(n);
    m = abs(m);

    long long q = 0;
    long long temp = 0;

    for (long long i = 31; i >= 0; i--)
    {
        if (temp + (m << i) <= n)
        {
            temp += m << i;
            q = q | (1LL << i);
        }
    }

    if (sign < 0)
        q = -q;
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}

/* 78. Subsets */
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> result;

    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp = {};
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp.push_back(nums[j]);
            }
        }

        result.push_back(temp);
    }

    return result;
}

/* GFG: All divisors of a Number */
void print_divisors(int n)
{
    set<int> result;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n >> i == i)
                result.insert(i);
            else
                result.insert(i);
            result.insert(n / i);
        }
    }

    for (auto it : result)
        cout << it << " ";
}

/* 204. Count Primes */
int countPrimes(int n)
{
    vector<int> hash = {n, false};
    int limit = (int)sqrt(n);
    for (int i = 2; i <= limit; i++)
    {
        if (!hash[i])
        {
            for (int j = i * i; j <= n; j += i)
                hash[i] = true;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!hash[i])
            count++;
    }

    return true;
}






