/*
 * Created by liyechen
 * Time 2020/04/27 11:21
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int rowCur = 0;
        while (rowCur <= rowIndex) {
            if (rowCur > 0) {
                int temp = ans[0];
                for (int i = 1; i < ans.size(); i++) {
                    ans[i] = temp + ans[i]; 
                    temp = ans[i] - temp;
                } 
            }
            ans.push_back(1);
            rowCur++;
        }
        return ans;
    }
};
