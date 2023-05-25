/* 1021. Remove Outermost Parentheses */
string removeOuterParentheses(string s)
{
    string str = "";

    int open = 0;
    for (auto c : s)
    {
        if (c == '(' && open++ > 0)
            str += '(';
        else if (c == ')' && open-- > 1)
            str += ')';
    }

    return str;
}

/* 1903. Largest Odd Number in String */
string largestOddNumber(string num)
{

    int n = num.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (num[i] % 2 == 0)
            num.pop_back();
        else
            break;
    }

    return num;
}

/* 14. Longest Common Prefix */
string longestCommonPrefix(vector<string> &strs)
{

    string result = "";
    int n = strs.size();
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[n - 1];
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] != last[i])
            break;
        result.push_back(first[i]);
    }

    return result;
}

/* 205. Isomorphic Strings */
bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> freq;
    unordered_map<char, bool> used;

    for (int i = 0; i < s.size(); i++)
    {
        if (freq.count(s[i]))
        {
            if (freq[s[i]] != t[i])
                return false;
        }
        else
        {
            if (used[t[i]])
                return false;

            freq[s[i]] = t[i];
            used[t[i]] = true;
        }
    }

    return true;
}

/* 242. Valid Anagram */
bool isAnagram(string s, string t)
{
    int freq[26] = {0};

    for (auto it : s)
        freq[it - 'a']++;

    for (auto it : t)
        freq[it - 'a']--;

    for (auto it : freq)
        if (it != 0)
            return false;

    return true;
}

/* 796. Rotate String */
bool rotateString(string s, string goal)
{
    queue<char> q1;
    queue<char> q2;

    for (auto it : s)
        q1.push(it);

    for (auto it : goal)
        q2.push(it);

    for (int i = 0; i < s.size(); i++)
    {
        char c = q1.front();
        q1.pop();
        q1.push(c);

        if (q1 == q2)
            return true;
    }

    return false;
}

/* 13. Roman to Integer */
int romanToInt(string s)
{
    map<char, int> roman{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int n = s.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (roman[s[i]] < roman[s[i + 1]])
            result -= roman[s[i]];
        else
            result += roman[s[i]];
    }

    return result;
}