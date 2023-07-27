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
