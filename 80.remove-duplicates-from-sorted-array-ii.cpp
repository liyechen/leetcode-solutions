/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    // [0,0,1,1,1,1,2,3,3]
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n == 0) return ans;

        int lastNumber = nums[0];
        int timeOfRepeat = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == lastNumber) {
                if (++timeOfRepeat > 2) ans++;
            } else {
                lastNumber = nums[i];
                timeOfRepeat = 1;
            }
            nums[i - ans] = nums[i];
        }

        return n - ans;
    }
};
// @lc code=end

