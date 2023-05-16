/* 4. Median of Two Sorted Arrays */

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int left = 0, right = n1;

    while (left <= right)
    {
        int partition1 = (left + right) >> 1;
        int partition2 = (n1 + n2 + 1) / 2 - partition1;

        int left1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
        int left2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
        int right1 = partition1 == n1 ? INT_MAX : nums1[partition1];
        int right2 = partition2 == n2 ? INT_MAX : nums2[partition2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            right = partition1 - 1;
        }
        else
        {
            left = partition1 + 1;
        }
    }

    return 0.0;
}