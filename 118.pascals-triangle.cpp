/*
 * Created by liyechen
 * Time 2020/04/27 11:14
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int rowCur = 1;
        while (rowCur <= numRows) {
            vector<int> row;
            row.push_back(1);
            if (rowCur != 1) {
                auto prevRow = ans[rowCur - 2];
                for (int i = 0; i < rowCur - 2; i++) {
                    row.push_back(prevRow[i] + prevRow[i + 1]);
                }
                row.push_back(1);
            }
            ans.push_back(row);
            rowCur++;
        }
        return ans;
    }
};
