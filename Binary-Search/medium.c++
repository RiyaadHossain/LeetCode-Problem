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