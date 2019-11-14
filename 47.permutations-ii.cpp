/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
// class Solution {

//     void track(vector<vector<int>>& ans, int k, vector<int> nums) {
//         int n = nums.size();
//         if (k == n - 1) {
//             ans.push_back(nums);
//             return;
//         }

//         // keep tracking

//         unordered_set<int> trackedNums;
//         for (int i = k; i < n; i++) {
//             if (trackedNums.find(nums[i]) == trackedNums.end()) {
//                 int temp = nums[i];
//                 nums[i] = nums[k];
//                 nums[k] = temp;

//                 track(ans, k + 1, nums);
                
//                 // nums[k] = nums[i];
//                 // nums[i] = temp;

//                 trackedNums.insert(nums[i]);
//             }
//         }
//     }

// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;

//         track(ans, 0, nums);
        
//         return ans;
//     }
// };

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
// @lc code=end

