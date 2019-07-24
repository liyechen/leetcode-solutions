/*
 * Created by haduluoke
 * Time 2019/07/24 14:37
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftScanner = 0, rightScanner = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while(leftScanner < rightScanner) {
            if (height[leftScanner] < height[rightScanner]) {
                // move left scanner
                if (height[leftScanner] > leftMax) {
                    leftMax = height[leftScanner];
                } else {
                    ans += leftMax - height[leftScanner];
                }
                leftScanner++;
            } else {
                if (height[rightScanner] > rightMax) {
                    rightMax = height[rightScanner];
                } else {
                    ans += rightMax - height[rightScanner];
                }
                rightScanner--;
            }
        }
        return ans;
    }
};
