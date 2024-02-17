#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        int a=0;
        for(auto i= 0;i<nums.size();i++)
        {
            a=a^nums[i];
        }
        return a;
    }
};