#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios::sync_with_stdio(false);
        vector<int> ans;
        vector<int>sizeEnds(nums.size(),1);
        vector<int>prev(nums.size(),-1);
        int max =0;
        int in=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0 && sizeEnds[i]<sizeEnds[j]+1){
                    sizeEnds[i]=sizeEnds[j]+1;
                    prev[i]=j;
                }
            }
            if(max<sizeEnds[i])
            {
                max= sizeEnds[i];
                in=i;
            }
        }
        while(in!=-1)
        {
            ans.push_back(nums[in]);
            in=prev[in];
        }
        return ans;
    }
};