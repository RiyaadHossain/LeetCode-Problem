/* 907. Sum of Subarray Minimums */

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {

        stack<int> st;
        int size = arr.size();
        vector<int> nsl(size, -1);
        vector<int> nsr(size, size);

        // 1. Generate NSL array
        for (int i = 0; i < size; i++)
        {
            int currEle = arr[i];
            while (!st.empty() && arr[st.top()] >= currEle)
            {
                st.pop();
            }

            if (!st.empty())
            {
                nsl[i] = st.top();
            }

            st.push(i);
        }

        // Make the stack empty
        while (!st.empty())
        {
            st.pop();
        }

        // 2. Generate NSR array
        for (int i = size - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] > curr)
            {
                st.pop();
            }

            if (!st.empty())
            {
                nsr[i] = st.top();
            }

            st.push(i);
        }

        // 3. Find sum of Min Subarray
        int Mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < size; i++)
        {
            long long left = (i - nsl[i]);
            long long right = (nsr[i] - i);
            long long currSum = left * right * arr[i];
            sum = (sum + currSum) % Mod;
        }

        return sum;
    }
};
