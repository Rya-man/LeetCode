class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
      ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i = 0;

    for (const int num : nums)
      if (num != val)
        nums[i++] = num;

    return i;
  }
};
