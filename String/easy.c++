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