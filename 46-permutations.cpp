/*
 * Created by liyechen
 * Time 2019/07/25 20:30
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        if (nums.size() == 1) {
            ans.push_back({ nums[0] });
            return ans;
        }
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            
            vector<int> leftSub(nums.begin(), nums.begin() + i);
            if (i < nums.size() - 1) { 
                vector<int> rightSub(nums.begin() + i + 1, nums.end());
                leftSub.insert(leftSub.end(), rightSub.begin(), rightSub.end());
            }
            vector<vector<int>> subPermutes = permute(leftSub);
            
            for (const vector<int> subPermute: subPermutes) {
                vector<int> subVec;
                subVec.push_back(num);
                subVec.insert(subVec.end(), subPermute.begin(), subPermute.end());
                ans.push_back(subVec);
            }
        }
        return ans;
    }
};
