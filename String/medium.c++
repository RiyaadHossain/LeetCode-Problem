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
        cout << s;
        cout << " " << end << endl;

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