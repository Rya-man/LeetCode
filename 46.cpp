class Solution {
public:
    vector<vector<int>> sol;

    inline void swapper(auto& i, auto& j) {
        auto t = i;
        i = j;
        j = t;
    }

    void helper(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            sol.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            swapper(nums[j], nums[i]);
            helper(i + 1, nums);
            swapper(nums[j], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(0, nums);
        return sol;
    }
};
