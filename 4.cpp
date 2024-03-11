/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/










#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    if (n1 > n2)
      return findMedianSortedArrays(nums2, nums1);

    int l = 0;
    int r = n1;

    while (l <= r) {
      const int partition1 = (l + r) / 2;
      const int partition2 = (n1 + n2 + 1) / 2 - partition1;
      const int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
      const int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
      const int minRight1 = partition1 == n1 ? INT_MAX : nums1[partition1];
      const int minRight2 = partition2 == n2 ? INT_MAX : nums2[partition2];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        return (n1 + n2) % 2 == 0
                   ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) * 0.5
                   : max(maxLeft1, maxLeft2);
      else if (maxLeft1 > minRight2)
        r = partition1 - 1;
      else
        l = partition1 + 1;
    }

    throw;
  }
};