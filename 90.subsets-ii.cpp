/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start

// solution:
/*
subsets([1,2,3,4]) = []
                    // push(1)
                    [1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
                    // pop(), push(2)
                    [2, subsets([3,4])]
                    // pop(), push(3)
                    [3, subsets([4])]
                    // pop(), push(4)
                    [4, subsets([])]
                    // pop()
*/
class Solution {

    void track(vector<vector<int>>& ans, vector<int> locus, vector<int>& nums, int pos) {
        ans.push_back(locus);

        int n = nums.size();

        for (int i = pos; i < n; i++) {
            if (i == pos || nums[i] != nums[i - 1]) {
                locus.push_back(nums[i]);
                track(ans, locus, nums, i + 1);
                locus.pop_back();
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) return ans;

        track(ans, vector<int>(), nums, 0);

        return ans;
    }
};
// @lc code=end

