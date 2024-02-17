/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        ios::sync_with_stdio(false);
        vector<int> dp(n+1,n);
        dp[0]=0;
        dp[1]=1; 
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j*j <=i;j++)
            {
                dp[i]=min(dp[i],dp[i- j*j]+1);
            }
        }
        return dp[n];
    }
};