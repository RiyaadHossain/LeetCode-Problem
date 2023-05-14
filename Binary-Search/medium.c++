/* 33. Search in Rotated Sorted Array */\int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

/* 34. Find First and Last Position of Element in Sorted Array */
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};

    // First Occurence
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans[0] = mid;
            right = mid - 1;
        }
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    // Last Occurence
    left = 0;
    right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            ans[1] = mid;

            left = mid + 1;
        }
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return ans;
}

/* 74. Search a 2D Matrix */
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size(), col = matrix[0].size();
    int left = 0, right = row * col - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int i = mid / col, j = mid % col;
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}

/* 81. Search in Rotated Sorted Array II */
bool search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[left] <= nums[mid])
        {
            if (nums[left] == nums[mid])
            {
                left++;
                mid--;
            }
            else if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return false;
}