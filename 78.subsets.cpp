/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

class Solution {

    void trackCombine(vector<vector<int>>& ans, vector<int> comb, const vector<int>& nums, int pos) {
        int size = comb.size();
        ans.push_back(comb);

        int n = nums.size();
        for (int i = pos; i < n; i++) {
            comb.push_back(nums[i]);
            trackCombine(ans, comb, nums, i + 1);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // C(n, k)
        // backtracking
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) return ans;

        vector<int> elem;
        trackCombine(ans, elem, nums, 0);

        return ans;
    }
};
// @lc code=end

