/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// int maxans=INT_MIN;
// int dp;
    int helper(vector<int>& arr, int k,int index,vector<int>& dp)
    {
        if(index==arr.size())
        return 0;
        if(dp[index]!=-1)
        return dp[index];
        int maxans=INT_MIN;
        int max=INT_MIN;
        int n= arr.size();
        for(int i=index,len=0;i<min(index+k,n);i++)
        {
            len++;
            max= max>arr[i]?max:arr[i];
            int sum=(len*max)+helper(arr,k,i+1,dp);
            maxans= maxans>sum?maxans:sum;
        }
        return dp[index]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        int n= arr.size();
        vector<int> dp(n,-1);
        return helper(arr,k,0,dp);
    }
};