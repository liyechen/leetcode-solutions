/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> collections;

        int ans = 0;
        for (int num : nums) {
            if (collections.find(num) == collections.end()) {
                int left = collections.find(num - 1) == collections.end() ? 0 : collections.at(num - 1);
                int right = collections.find(num + 1) == collections.end() ? 0 : collections.at(num + 1);
            
                int sum = left + right + 1;

                // update ans
                ans = max(ans, sum);

                collections.insert_or_assign(num, sum);

                collections.insert_or_assign(num - left, sum);
                collections.insert_or_assign(num + right, sum);

            }
        }
        
        return ans;

    }
};
// @lc code=end

