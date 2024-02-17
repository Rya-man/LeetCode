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