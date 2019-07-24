/*
 * Created by liyechen
 * Time 2019/07/24 15:42
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums.size() || nums[i] <= 0) nums[i] = INT_MAX;
        }
        int j;
        for (unsigned int i = 0; i < nums.size(); i++) {
            j = abs(nums[i]) - 1;
            if (j + 1 < INT_MAX) {
                nums[j] = -abs(nums[j]);
            }
        }
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
