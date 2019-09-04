/*
 * Created by liyechen
 * Time 2019/09/04 16:47
 * Email <gliyechen@hotmail.com>
 */

class Solution {
private:
    enum DIRECTION { RIGHT = 0, LEFT, TOP, BOTTOM };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; 
        if (matrix.empty()) return ans;
        int row = 0, col = 0;
        ans.push_back(matrix[row][col]);
        int leftBound = 0, topBound = 1, rightBound = matrix[0].size() - 1, bottomBound = matrix.size() - 1;
        DIRECTION direction = RIGHT;
        while(true) {
            switch(direction) {
                case RIGHT:
                    for (int i = col + 1; i <= rightBound; i++) {
                        ans.push_back(matrix[row][i]);
                    }
                    col = rightBound;
                    rightBound--;
                    direction = BOTTOM;
                    if (row == bottomBound) return ans;
                    break;
                case LEFT:
                    for (int i = col - 1; i >= leftBound; i--) {
                        ans.push_back(matrix[row][i]);
                    }
                    col = leftBound;
                    leftBound++;
                    direction = TOP;
                    if (topBound == row) return ans;
                    break;
                case TOP:
                    for (int i = row - 1; i >= topBound; i--) {
                        ans.push_back(matrix[i][col]);
                    }
                    row = topBound;
                    direction = RIGHT;
                    topBound++;
                    if (rightBound == col) return ans;
                    break;
                case BOTTOM:
                    for (int i = row + 1; i <= bottomBound; i++) {
                        ans.push_back(matrix[i][col]);
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
