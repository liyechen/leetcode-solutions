/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n < 0) return 0;

        stack<int> blocks;

        int ans = 0;
        int i = 0;

        while (i < n) {
            if (blocks.empty() || heights[i] >= heights[blocks.top()]) {
                blocks.push(i++);
            } else {
                int last = blocks.top();
                blocks.pop();

                int area = heights[last] * (blocks.empty() ? i : (i - blocks.top() - 1));
                ans = max(ans, area);
            }
        }

        // 最后的单调增序列
        while (!blocks.empty()) {
            int last = blocks.top();
            blocks.pop();

            int area = heights[last] * (blocks.empty() ? i : (i - blocks.top() - 1));
            ans = max(ans, area);
        }

        return ans;
    }
};
// @lc code=end

