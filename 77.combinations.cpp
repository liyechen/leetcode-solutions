/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {

    void trackCombine(vector<vector<int>>& ans, vector<int> comb, int k, int nums[], int n) {
        int size = comb.size();
        if (size == k) {
            ans.push_back(comb);
            return;
        }

        int startPos = size == 0 ? 0 : comb[size - 1];

        for (int i = startPos; i < n; i++) {
            comb.push_back(nums[i]);
            trackCombine(ans, comb, k, nums, n);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        // C(n, k)
        // backtracking
        vector<vector<int>> ans;

        if (n < k) return ans;
        
        int nums[n];

        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        vector<int> elem;
        trackCombine(ans, elem, k, nums, n);

        return ans;
    }
};
// @lc code=end

