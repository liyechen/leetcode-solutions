/*
 * Created by liyechen
 * Time 2019/10/03 14:33
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        
        int cols = matrix[0].size();
        
        int left = 0, right = rows * cols - 1;
        int middle;
        while(right >= left) {
            middle = (right + left) / 2;
            int col = middle % cols;
            int row = (middle - col) / cols;
            
            int val = matrix[row][col];
            if (target == val) return true;
            if (target > val) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            
        }
        return false;
    }
};
