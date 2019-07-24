/*
 * Created by liyechen
 * Time 2019/07/24 15:44
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0") return "0";
        
        int l1 = num1.size(), l2 = num2.size();
        string ans = "";
        
        int values[l1 + l2] = { 0 };
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                int idx = l1 + l2 - i - j - 2;
                values[idx] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for (int i = 0; i < l1 + l2; i++) {
            if (values[i] >= 10) {
                values[i + 1] += (values[i] - values[i] % 10) / 10;
            }
            char temp = values[i] % 10 + '0';
            ans = temp + ans;
        }
        if (ans[0] == '0') return ans.substr(1, ans.size() - 1);
        return ans;
    }
};
