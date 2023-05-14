#include <bits/stdc++.h>
using namespace std;

/* 268. Missing Number */
int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

/* 278. First Bad Version */
int firstBadVersion(int n)
{
    int left = 0, right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

/* 349. Intersection of Two Arrays */
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size();
    int m = nums2.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums1[i] == nums1[i - 1])
        {
            continue; // Skip duplicate elements in nums1
        }
        if (isExsit(nums2, nums1[i]))
            ans.push_back(nums1[i]);
    }

    return ans;
}

bool isExsit(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

/* 367. Valid Perfect Square */
bool isPerfectSquare(int num)
{
    if (num < 2)
    {
        return true;
    }

    long long left = 0;
    long long right = num;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num)
        {
            return true;
        }
        else if (square > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}

