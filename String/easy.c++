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