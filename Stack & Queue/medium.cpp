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

/* 735. Asteroid Collision */
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> result;

        for (int &a : asteroids)
        {
            while (!result.empty() && a < 0 && result.back() > 0)
            {
                int sum = a + result.back();

                if (sum < 0)
                {
                    result.pop_back();
                }
                else if (sum > 0)
                {
                    a = 0;
                }
                else
                {
                    result.pop_back();
                    a = 0;
                }
            }

            if (a != 0)
                result.push_back(a);
        }

        return result;
    }
};

/* 402. Remove K Digits */
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string result;
        stack<char> st;
        st.push(num[0]);

        if (k < 0)
            return num;
        if (k > num.size())
            return "0";

        for (int i = 1; i < num.size(); i++)
        {
            while (k > 0 && !st.empty() && num[i] < st.top())
            {
                k--;
                st.pop();
            }

            st.push(num[i]);

            if (st.size() == 1 && st.top() == '0')
                st.pop();
        }

        while (k > 0 && !st.empty())
        {
            k--;
            st.pop();
        };

        if (st.empty())
            return "0";

        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

/* 901. Online Stock Span */
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span = span + st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/* 146. LRU Cache */
/* 
    🚀 Intution: 
    - Firt of all, We'll use HashMap to store all the value, so that we can access any value in O(1) using key.
    - Secondly, to track the least recent used(LRU) element we'll use list data structure. Just to acess any element in O(1) using pointer. 
    - So, we'll also store pointer address in the HashMap.
*/


class LRUCache
{
public:
    // Initialize list + map + n
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mpp;
    int n;

    LRUCache(int capacity)
    {
        n = capacity;
    }

    void markRecentUsed(int key)
    {
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }

    int get(int key)
    {
        // If key is not present
        if (mpp.find(key) == mpp.end())
            return -1;

        // Update as Recently used
        markRecentUsed(key);
        return mpp[key].second;
    }

    void put(int key, int value)
    {
        // If key is already exist (Update value + Mark as Recent used)
        if (mpp.find(key) != mpp.end())
        {
            // Update value
            mpp[key] = {mpp[key].first, value};
            // Mark as Recent used
            markRecentUsed(key);
            return;
        }

        // Decrement Limit
        n--;
        // Store Key
        dll.push_front(key);
        // Update mpp
        mpp[key] = {dll.begin(), value};

        // If limit exceed
        if (n < 0)
        {
            int key_tobe_del = dll.back();
            // Remove from mpp
            mpp.erase(key_tobe_del);
            // Remove from dll
            dll.pop_back();
            n++;
        }
    }
};
