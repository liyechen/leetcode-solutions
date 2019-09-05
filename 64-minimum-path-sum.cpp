/*
 * Created by liyechen
 * Time 2019/09/05 15:21
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        for (int row = 1; row < rows; row++) {
            grid[row][0] = grid[row][0] + grid[row - 1][0];
        }
        for (int col = 1; col < cols; col++) {
            grid[0][col] = grid[0][col] + grid[0][col - 1];
        }
        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                grid[row][col] = min(grid[row - 1][col], grid[row][col - 1]) + grid[row][col];
            }
        }
        return grid[rows - 1][cols - 1];
    }
};
