/*
 * Created by liyechen
 * Time 2019/09/05 14:37
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans = 0;
        if (obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<unsigned int>> pathGrid(m, vector<unsigned int>(n, 0));

        // init path grid's first col and row
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0) pathGrid[0][i] = 1;
            else break;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) pathGrid[i][0] = 1;
            else break;
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                if (obstacleGrid[row][col] == 0) {
                    pathGrid[row][col] = pathGrid[row - 1][col] + pathGrid[row][col - 1];
                } else {
                    pathGrid[row][col] = 0;
                }
            }
        }
        return pathGrid[m - 1][n - 1];
    }
};

