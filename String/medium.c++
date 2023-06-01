/* 151. Reverse Words in a String */

string reverseWords(string s)
{

    reverse(s.begin(), s.end());
    int start = 0, end = 0, i = 0, n = s.size();

    while (i < n)
    {
        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Find the end of the current word
        while (i < n && s[i] != ' ')
        {
            s[end] = s[i];
            end++;
            i++;
        }

        while (start < end)
        {
            // Reverse the current word
            reverse(s.begin() + start, s.begin() + end);

            // Add a space after the reversed word
            s[end] = ' ';
            end++;

            // Update the start index for the next word
            start = end;
        }

        i++;
    }

    // Remove extra space at the end if present
    if (end > 0)
        s.resize(end - 1);

    return s;
}

/* 451. Sort Characters By Frequency */
string frequencySort(string s)
{
    string ans = "";
    vector<pair<int, char>> hashTable('z' + 1, {0, 0});

    for (auto it : s)
        hashTable[it] = {hashTable[it].first + 1, it};

    sort(hashTable.begin(), hashTable.end());

    for (auto it : hashTable)
        ans = string(it.first, it.second) + ans;

    return ans;
}

/* 8. String to Integer (atoi) */
int myAtoi(string s)
{
    int n = s.size();
    double num = 0;
    int i = 0;
    while (s[i] == ' ')
        i++;

    bool pos = s[i] == '+';
    bool neg = s[i] == '-';

    if (pos | neg)
        i++;

    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }

    num = neg ? -num : num;

    num = num > INT_MAX ? INT_MAX : num;
    num = num < INT_MIN ? INT_MIN : num;

    return int(num);
}

/* 5. Longest Palindromic Substring */
string longestPalindrome(string s)
{
    int n = s.size();
    int max_len = 1;
    int st = 0;

    // Odd Palindromic Substring
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = i;
        int curr_len = 0;

        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                curr_len = r - l + 1;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }

        if (curr_len > max_len)
        {
            max_len = curr_len;
            st = l + 1;
        }
    }

    // Even Paliddromic Substring
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = i + 1;
        int curr_len = 0;

        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                curr_len = r - l + 1;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }

        if (curr_len > max_len)
        {
            max_len = curr_len;
            st = l + 1;
        }
    }

    return s.substr(st, max_len);
}

/* 1781. Sum of Beauty of All Substrings */
int beautySum(string s)
{
    int ans = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        int cnt[26] = {0};
        int max_freq = INT_MIN;
        int min_freq = INT_MAX;

        for (int j = i; j < n; j++)
        {
            int ind = s[j] - 'a';
            cnt[ind]++;
            max_freq = max(max_freq, cnt[ind]);
            min_freq = cnt[ind];

            for (int k = 0; k < 26; k++)
            {
                if (cnt[k] >= 1)
                    min_freq = min(min_freq, cnt[k]);
            }

            ans += (max_freq - min_freq);
        }
    }

    return ans;
}