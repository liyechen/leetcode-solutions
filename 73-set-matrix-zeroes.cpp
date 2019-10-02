/*
 * Created by liyechen
 * Time 2019/10/01 20:36
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> marked_rows;
        unordered_set<int> marked_cols;
        int rows = matrix.size();
        if (rows == 0) return;
        
        int cols = matrix[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    marked_rows.insert(row);
                    marked_cols.insert(col);
                }
            }
        }
        for (auto& row : marked_rows) {
            for (int col = 0; col < cols; col++) {
                matrix[row][col] = 0;
            }
        }

        for (auto& col : marked_cols) {
            for (int row = 0; row < rows; row++) {
                matrix[row][col] = 0;
            }
        }
    }
};
