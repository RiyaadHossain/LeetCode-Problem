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

/* 39. Combination Sum */
class Solution
{
private:
    void solve(vector<vector<int>> &output, vector<int> candidates, vector<int> temp, int idx, int ourSum, int target)
    {

        // Base Case
        if (ourSum >= target)
        {
            if (ourSum == target)
                output.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {

            // Count Sum and Add Element
            ourSum += candidates[i];
            temp.push_back(candidates[i]);
            solve(output, candidates, temp, i, ourSum, target);

            // Backtracking
            ourSum -= candidates[i];
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> output;
        vector<int> temp;
        solve(output, candidates, temp, 0, 0, target);
        return output;
    }
};

/* 90. Subsets II */
class Solution
{
private:
    void solve(vector<vector<int>> &output, vector<int> nums, vector<int> ans, int idx)
    {
        output.push_back(ans);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i] == nums[i - 1])
                continue;
            ans.push_back(nums[i]);
            solve(output, nums, ans, i + 1);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> output;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        solve(output, nums, ans, 0);
        return output;
    }
};

/* 216. Combination Sum III */
class Solution
{
private:
    void solve(vector<vector<int>> &output, vector<int> nums, vector<int> ans, int expectedLen, int ourSum, int target, int idx)
    {
        if (ourSum == target && ans.size() == expectedLen)
        {
            output.push_back(ans);
            return;
        }

        if (nums.size() <= idx)
            return;
        if (ans.size() == expectedLen)
            return;

        for (int i = idx; i < nums.size(); i++)
        {
            if (nums[i] + ourSum > target)
                break;

            ourSum += nums[i];
            ans.push_back(nums[i]);
            solve(output, nums, ans, expectedLen, ourSum, target, i + 1);

            // Backtracking
            ourSum -= nums[i];
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> output;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ans;
        solve(output, nums, ans, k, 0, n, 0);
        return output;
    }
};

