/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.*/

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