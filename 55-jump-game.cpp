/*
 * Created by liyechen
 * Time 2019/09/04 18:30
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int position = 0;
        while(true) {
            int maxLength = 0;
            int maxI = 0;
            for (int i = 1; i <= nums[position] && i + position < nums.size(); i++) {
                if (nums[position + i] + i > maxLength) {
                    maxLength = nums[position + i] + i;
                    maxI = i;
                }
            }
            if (maxI == 0) return false;
            position = maxI + position;
            if (position >= nums.size() - 1) return true;
        }
        return false;
    }
};

