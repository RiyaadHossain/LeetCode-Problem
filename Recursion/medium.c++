/* 22. Generate Parentheses */
class Solution
{
    void solve(vector<string> &output, string temp, int open, int close)
    {

        // Base Case
        if (open == 0 && close == 0)
        {
            output.push_back(temp);
            return;
        };

        if (open == close)
        {
            // Push '(' bracket
            string temp1 = temp;
            temp1.push_back('(');
            solve(output, temp1, open - 1, close);
        }
        else if (open == 0)
        {
            // Push ')' bracket
            string temp1 = temp;
            temp1.push_back(')');
            solve(output, temp1, open, close - 1);
        }
        else
        {
            // Push '(' and ')' brackets
            string temp1 = temp;
            string temp2 = temp;
            temp1.push_back('(');
            temp2.push_back(')');
            solve(output, temp1, open - 1, close);
            solve(output, temp2, open, close - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp = "(";
        solve(ans, temp, n - 1, n);

        return ans;
    }
};

/* 78. Subsets */
class Solution
{
private:
    void solve(vector<vector<int>> &result, vector<int> temp, vector<int> nums, int index)
    {
        if (index == nums.size())
        {
            result.push_back(temp);
            return;
        }

        vector<int> temp1 = temp;
        temp1.push_back(nums[index]);
        solve(result, temp1, nums, index + 1);
        solve(result, temp, nums, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> temp;
        solve(result, temp, nums, 0);
        return result;
    }
};