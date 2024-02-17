#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios::sync_with_stdio(false);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int max=-1;
        for(auto x: mp)
        {
            if(x.second> nums.size()/2)
            return x.first;
        }
        return -1;
    }
};