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

/* 84. Largest Rectangle in Histogram */
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int size = heights.size();
        stack<int> st;
        vector<int> NGL(size, 0);
        vector<int> NGR(size, size);

        // 1. NGL
        for (int i = 0; i < size; i++)
        {
            int curr = heights[i];
            while (!st.empty() && curr < heights[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
                NGL[i] = st.top() + 1;

            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        // 2. NGR
        for (int i = size - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (!st.empty() && curr <= heights[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
                NGR[i] = st.top();

            st.push(i);
        }

        // 3. Max Width
        int max_width = 0;
        for (int i = 0; i < size; i++)
        {
            int width = (NGR[i] - NGL[i]) * heights[i];
            max_width = max(max_width, width);
        }

        return max_width;
    }
};

/* 85. Maximal Rectangle */
class Solution
{
private:
    int findRectangle(vector<int> heights)
    {
        stack<int> st;
        int size = heights.size();
        vector<int> NGL(size, 0);
        vector<int> NGR(size, size);

        // 1. NGL
        for (int i = 0; i < size; i++)
        {
            int curr = heights[i];
            while (!st.empty() && curr < heights[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
                NGL[i] = st.top() + 1;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // 1. NGR
        for (int i = size - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (!st.empty() && curr <= heights[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
                NGR[i] = st.top();

            st.push(i);
        }

        // 1. Max Width
        int max_width = 0;
        for (int i = 0; i < size; i++)
        {
            int width = (NGR[i] - NGL[i]) * heights[i];
            max_width = max(max_width, width);
        }
        return max_width;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int colSize = matrix.size();
        int rowSize = matrix[0].size();
        vector<int> eachRow(rowSize, 0);

        vector<vector<int>> matrixNum(colSize);
        for (int i = 0; i < colSize; i++)
        {
            vector<int> temp(rowSize, 0);
            for (int j = 0; j < rowSize; j++)
            {
                temp[j] = matrix[i][j] - '0';
            }

            matrixNum[i] = temp;
        }

        int max_rectangle = findRectangle(matrixNum[0]);
        for (int i = 0; i < colSize; i++)
        {
            for (int j = 0; j < rowSize; j++)
            {
                if (matrixNum[i][j] == 1)
                    eachRow[j]++;
                else
                    eachRow[j] = 0;
            }

            int width = findRectangle(eachRow);
            max_rectangle = max(max_rectangle, width);
        }

        return max_rectangle;
    }
};

/* 239. Sliding Window Maximum */
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> result;

        // 1. Find max in the first k element
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Find max element in the nums and store to the result
        for (int i = k; i < nums.size(); i++)
        {

            // Push the first max element
            result.push_back(nums[dq.front()]);

            // Pop if the k number of element exceed
            while (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            // Pop back if current elemet is greater
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        if (!dq.empty())
            result.push_back(nums[dq.front()]);

        return result;
    }
};
