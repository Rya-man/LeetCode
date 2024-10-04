class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size()-1;

        int mid = left + (right-left)/2;

        while(left <= right)
        {
            mid = left + (right-left)/2;
            if(nums[mid]==target)
            return mid;

            if(target < nums[mid])
            right = mid-1;

            if(target>nums[mid])
            left = mid+1;

        }
        return left;
    }
};
