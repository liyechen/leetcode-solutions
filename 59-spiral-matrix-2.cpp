/*
 * Created by liyechen
 * Time 2019/09/05 11:46
 * Email <gliyechen@hotmail.com>
 */

class Solution {
private:
    enum Direction { RIGHT = 0, LEFT, TOP, BOTTOM };
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int row = 0, col = 0;
        int path = 1;
        ans[row][col] = path;
        path = 2;
        int leftBound = 0, topBound = 1, rightBound = n - 1, bottomBound = n - 1;
        Direction direction = RIGHT;
        while(true) {
            switch(direction) {
                case RIGHT:
                    for (int i = col + 1; i <= rightBound; i++) {
                        ans[row][i] = path;
                        path++;
                    }
                    col = rightBound;
                    rightBound--;
                    direction = BOTTOM;
                    if (row == bottomBound) return ans;
                    break;
                case LEFT:
                    for (int i = col - 1; i >= leftBound; i--) {
                        ans[row][i] = path;
                        path++;
                    }
                    col = leftBound;
                    leftBound++;
                    direction = TOP;
                    if (topBound == row) return ans;
                    break;
                case TOP:
                    for (int i = row - 1; i >= topBound; i--) {
                        ans[i][col] = path;
                        path++;
                    }
                    row = topBound;
                    direction = RIGHT;
                    topBound++;
                    if (rightBound == col) return ans;
                    break;
                case BOTTOM:
                    for (int i = row + 1; i <= bottomBound; i++) {
                        ans[i][col] = path;
                        path++;
                    }
                    row = bottomBound;
                    direction = LEFT;
                    bottomBound--;
                    if (leftBound == col) return ans;
                    break;
                default:
                    break;
            }
        }

        return ans;
    }
};
