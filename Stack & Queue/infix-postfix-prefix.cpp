/* Infix To Postfix */
#include <stack>
#include <string>

int precedence(char symbol)
{
    if (symbol == '^')
        return 3;
    else if (symbol == '*')
        return 2;
    else if (symbol == '/')
        return 2;
    else if (symbol == '+')
        return 1;
    else if (symbol == '-')
        return 1;

    return 0;
}

string infixToPostfix(string exp)
{
    string result;
    stack<char> oparator;

    for (int i = 0; i < exp.length(); i++)
    {
        char symbol = exp[i];

        switch (symbol)
        {
        case '(':
            oparator.push(symbol);
            break;

        case ')':
            while (oparator.top() != '(')
            {
                char firstOpa = oparator.top();
                result.push_back(firstOpa);
                oparator.pop();
            }

            oparator.pop();
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if (!oparator.empty() && precedence(oparator.top()) >= precedence(symbol))
            {
                while (!oparator.empty() && precedence(oparator.top()) >= precedence(symbol))
                {
                    char firstOpa = oparator.top();
                    result.push_back(firstOpa);
                    oparator.pop();
                }
                oparator.push(symbol);
            }
            else
            {
                oparator.push(symbol);
            }

            break;

        default:
            result.push_back(symbol);
        }
    }

    while (!oparator.empty())
    {
        char firstOpa = oparator.top();
        result.push_back(firstOpa);
        oparator.pop();
    }

    return result;
}

/* Prefix to Infix */
#include <string>
#include <stack>

bool isOparator(char symbol)
{
    if (symbol == '^' || symbol == '/' || symbol == '*' || symbol == '-' || symbol == '+')
        return true;

    return false;
}

string prefixToInfixConversion(string &s)
{
    stack<string> st;
    int size = s.length();

    for (int i = size - 1; i >= 0; i--)
    {
        char symbol = s[i];

        if (isOparator(symbol))
        {
            string firstElem = st.top();
            st.pop();
            string secondElem = st.top();
            st.pop();

            string mathExp = "(" + firstElem + string(1, symbol) + secondElem + ")";
            st.push(mathExp);
        }
        else
        {
            st.push(string(1, symbol));
        }
    }

    return st.top();
}

/* Convert Prefix to Postfix */
#include <string>
#include <stack>

bool isOparator(char symbol)
{
    if (symbol == '^' || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-')
        return true;

    return false;
}

string preToPost(string s)
{
    stack<string> st;
    int size = s.length();

    for (int i = size - 1; i >= 0; i--)
    {
        char symbol = s[i];

        if (isOparator(symbol))
        {
            string firstEl = st.top();
            st.pop();
            string secondEl = st.top();
            st.pop();

            string mathExp = firstEl + secondEl + symbol;
            st.push(mathExp);
        }
        else
        {
            st.push(string(1, symbol));
        }
    }

    return st.top();
}

/* PostFix To Prefix */
#include <string>
#include <stack>

bool isOparator(string symbol)
{
    if (symbol == "^" || symbol == "*" || symbol == "/" || symbol == "+" || symbol == "-")
        return true;

    return false;
}

string postfixToPrefix(string &s)
{
    stack<string> st;
    int size = s.length();

    for (int i = 0; i < size; i++)
    {
        string symbol = string(1, s[i]);

        if (isOparator(symbol))
        {
            string firstEl = st.top();
            st.pop();
            string secondEl = st.top();
            st.pop();

            string mathExp = symbol + secondEl + firstEl;
            st.push(mathExp);
        }
        else
        {
            st.push(symbol);
        }
    }

    return st.top();
}

/* Postfix to Infix */
bool isOparator(string symbol)
{
    if (symbol == "^" || symbol == "*" || symbol == "/" || symbol == "+" || symbol == "-")
        return true;

    return false;
}

string postToInfix(string postfix)
{
    stack<string> st;
    int size = postfix.length();

    for (int i = 0; i < size; i++)
    {
        string symbol = string(1, postfix[i]);

        if (isOparator(symbol))
        {
            string firstElem = st.top();
            st.pop();
            string secondElem = st.top();
            st.pop();

            string mathExp = "(" + secondElem + symbol + firstElem + ")";
            st.push(mathExp);
        }
        else
        {
            st.push(symbol);
        }
    }

    return st.top();
}