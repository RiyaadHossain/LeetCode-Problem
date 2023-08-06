/* 225. Implement Stack using Queues */
class MyStack
{
    queue<int> qu;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        int size = qu.size();
        qu.push(x);

        for (int i = 0; i < size; i++)
        {
            int top = qu.front();
            qu.push(top);
            qu.pop();
        }
    }

    int pop()
    {
        int val = qu.front();
        qu.pop();
        return val;
    }

    int top()
    {
        return qu.front();
    }

    bool empty()
    {
        return qu.empty();
    }
};

/* 232. Implement Queue using Stacks */
class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int val = st.top();
        st.pop();
        push(x);
        st.push(val);
    }

    int pop()
    {
        int val = st.top();
        st.pop();
        return val;
    }

    int peek()
    {
        return st.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

/* Implement Queue Using Linked List */
Node *front = NULL;
Node *rear = NULL;

void Queue::push(int x)
{
    Node *newNode = new Node(x);
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::pop()
{
    if (front != NULL)
    {
        int val = front->data;
        Node *nextNode = front->next;
        front->next = nextNode;
        delete front;
        front = nextNode;

        return val;
    }

    return -1;
}

/* 20. Valid Parentheses */
class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> st;
        int len = s.length();

        if (len % 2 == 1)
            return false;

        for (int i = 0; i < len; i++)
        {
            char curr = s[i];
            if (curr == '(' || curr == '{' || curr == '[')
                st.push(curr);
            else
            {
                if (st.empty())
                    return false;
                if (curr == ')' && st.top() != '(')
                    return false;
                if (curr == '}' && st.top() != '{')
                    return false;
                if (curr == ']' && st.top() != '[')
                    return false;

                if (!st.empty())
                    st.pop();
            }
        }

        return st.empty();
    }
};

/* 496. Next Greater Element I */
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ump;
        stack<int> st;

        int size1 = nums1.size();
        int size2 = nums2.size();

        for (int i = size2 - 1; i >= 0; i--)
        {
            int curr = nums2[i];
            while (!st.empty() && st.top() < curr)
            {
                st.pop();
            }

            if (!st.empty())
                ump[curr] = st.top();
            else
                ump[curr] = -1;

            st.push(curr);
        }

        vector<int> result;
        for (int i = 0; i < size1; i++)
        {
            int curr = nums1[i];
            result.push_back(ump[curr]);
        }

        return result;
    }
};

/* Next Smaller Element */
#include <stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> result(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (!st.empty() && curr <= st.top())
            st.pop();

        if (!st.empty())
            result[i] = st.top();

        st.push(curr);
    }

    return result;
}