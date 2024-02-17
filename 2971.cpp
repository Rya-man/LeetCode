#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false);
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum=0;
        for (auto& it : nums)
        {
            sum+=it;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=sum-nums[i])
            {
                sum=sum-nums[i];
                continue;
            }
            else
            return sum;
        }
        return -1;
    }
};