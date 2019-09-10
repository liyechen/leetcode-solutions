/*
 * Created by liyechen
 * Time 2019/09/10 13:59
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x < 4) return 1;
        int left = 1, right = x / 2;
        while (true) {
            int mid = (left + right) / 2;
            if (mid > x / mid) {
                right = mid;
            } else {
                if (mid + 1 > x / (mid + 1)) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
};
