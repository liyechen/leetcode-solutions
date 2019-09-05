/*
 * Created by liyechen
 * Time 2019/09/05 15:30
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int m = digits.size();
        for (int k = m - 1; k >= 0; k--) {
            digits[k]++;
            if (digits[k] < 10) break;
            digits[k] = 0;
            if (k == 0) {
                digits.insert(digits.begin(), 1);
                break;
            }
        }
        return digits;
    }
};
