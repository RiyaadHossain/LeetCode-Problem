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

/* 17. Letter Combinations of a Phone Number */
class Solution
{
private:
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(vector<string> &output, string digits, string temp, int idx)
    {
        if (idx == digits.size())
        {
            output.push_back(temp);
            return;
        }

        int num = digits[idx] - '0';
        string codes = mapping[num];

        for (int i = 0; i < codes.size(); i++)
        {
            temp.push_back(codes[i]);
            solve(output, digits, temp, idx + 1);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> output;
        string temp;

        if (!digits.size())
            return output;

        solve(output, digits, temp, 0);
        return output;
    }
};

/* 131. Palindrome Partitioning */
class Solution
{
private:
    bool isPilandrome(string str)
    {
        int len = str.size();

        int i = 0;
        while (i <= len / 2)
        {
            if (str[i] != str[len - i - 1])
                return false;
            i++;
        }

        return true;
    }

    void helper(vector<vector<string>> &output, vector<string> temp, string str)
    {
        if (str.size() == 0)
            output.push_back(temp);

        for (int i = 0; i < str.size(); i++)
        {
            string left = str.substr(0, i + 1);
            if (isPilandrome(left))
            {
                temp.push_back(left);
                string right = str.substr(i + 1);
                helper(output, temp, right);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> output;
        vector<string> temp;
        helper(output, temp, s);
        return output;
    }
};

/* Word Search */
class Solution
{
    bool helperFunc(vector<vector<char>> &board, string word, int i, int j, int m, int n, int k)
    {

        // Base Case
        if (k == word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Return when curr element doesn't match
        if (board[i][j] != word[k] || board[i][j] == '.')
            return false;

        board[i][j] = '.';

        // Down
        if (helperFunc(board, word, i + 1, j, m, n, k + 1))
            return true;

        // Left
        if (helperFunc(board, word, i, j + 1, m, n, k + 1))
            return true;

        // Up
        if (helperFunc(board, word, i - 1, j, m, n, k + 1))
            return true;

        // Right
        if (helperFunc(board, word, i, j - 1, m, n, k + 1))
            return true;

        board[i][j] = word[k];

        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        if (m == 0 || n == 0)
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (helperFunc(board, word, i, j, m, n, 0))
                    return true;
            }
        }

        return false;
    }
};

/* 51. N-Queens */
class Solution
{
private:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        int tempRow = row;
        int tempCol = col;

        // Left Row
        while (tempCol >= 0)
        {
            if (board[tempRow][tempCol] == 'Q')
                return false;
            tempCol--;
        }

        // Upper Diagonal
        tempRow = row;
        tempCol = col;
        while (tempRow >= 0 && tempCol >= 0)
        {
            if (board[tempRow][tempCol] == 'Q')
                return false;
            tempRow--;
            tempCol--;
        }

        // Lower Diagonal
        tempRow = row;
        tempCol = col;
        while (tempRow < n && tempCol >= 0)
        {
            if (board[tempRow][tempCol] == 'Q')
                return false;
            tempRow++;
            tempCol--;
        }

        return true;
    }

private:
    void helperFunc(vector<vector<string>> &ans, vector<string> &board, int col, int n)
    {
        if (col >= n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, row, col, n))
            {
                board[row][col] = 'Q';
                helperFunc(ans, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);

        string str(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = str;
        }

        helperFunc(ans, board, 0, n);

        return ans;
    }
};
