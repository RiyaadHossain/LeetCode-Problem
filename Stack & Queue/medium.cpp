/* 155. Min Stack */
// #Approach 1
public:
stack<int> st, minSt;

MinStack()
{
}

void push(int val)
{

    if (minSt.empty() || val <= minSt.top())
    {
        minSt.push(val);
    }

    st.push(val);
}

void pop()
{
    if (st.empty())
        return;
    if (st.top() == minSt.top())
        minSt.pop();
    st.pop();
}

int top()
{
    if (st.empty())
        return -1;
    return st.top();
}

int getMin()
{
    if (minSt.empty())
        return -1;
    return minSt.top();
}

// #Approach 2
class MinStack
{
public:
    stack<int> st;
    int minVal = INT_MAX;

    MinStack()
    {
    }

    void push(int val)
    {
        if (minVal >= val)
        {
            st.push(minVal);
            minVal = val;
        }

        st.push(val);
    }

    void pop()
    {
        if (st.empty())
            return;

        if (st.top() == minVal)
        {
            st.pop();
            minVal = st.top();
        }

        st.pop();
    }

    int top()
    {
        return st.empty() ? -1 : st.top();
    }

    int getMin()
    {
        return minVal;
    }
};

/* 503. Next Greater Element II */
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        int size = nums.size();
        vector<int> result(size, -1);

        for (int i = size * 2; i >= 0; i--)
        {
            int curr = nums[i % size];
            while (!st.empty() && st.top() <= curr)
            {
                st.pop();
            }

            if (i < size)
            {
                if (!st.empty())
                    result[i] = st.top();
            }

            st.push(curr);
        }

        return result;
    }
};
