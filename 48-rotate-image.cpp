class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        if (length <= 1) return;
        
        int middle = (length - length % 2) / 2;
        
        int rows = length % 2 == 0 ? middle : middle + 1;
        int cols = middle;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int temp = matrix[i][j];
                // [i][j] -> [j][length - i - 1]
                matrix[i][j] = matrix[length - j - 1][i];
                matrix[length - j - 1][i] = matrix[length - i - 1][length - j - 1];
                matrix[length - i - 1][length - j - 1] = matrix[j][length - i - 1];
                matrix[j][length - i - 1] = temp;
            }
        }
    }
};
