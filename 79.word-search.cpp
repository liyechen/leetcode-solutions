/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {

    bool trackWord(const vector<vector<char>>& board, const string& word, string trackedWord, int row, int col, vector<vector<int>>& tracked) {
        // out of board
        if (row >= board.size() || row < 0) return false;
        if (col >= board[0].size() || col < 0) return false;

        // tracked before
        if (tracked[row][col] == 1) return false;

        // judge the incoming character
        int trackedLength = trackedWord.size();
        if (board[row][col] != word[trackedLength]) return false;

        
        if (trackedLength + 1 == word.size()) return true;
        trackedWord = trackedWord + word[trackedLength];
        tracked[row][col] = 1;

        if (trackWord(board, word, trackedWord, row + 1, col, tracked)) return true;
        if (trackWord(board, word, trackedWord, row - 1, col, tracked)) return true;
        if (trackWord(board, word, trackedWord, row, col + 1, tracked)) return true;
        if (trackWord(board, word, trackedWord, row, col - 1, tracked)) return true;
        
        tracked[row][col] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // backtracking
        int rows = board.size();
        if (rows == 0) return false;

        if (word == "") return true;

        int cols = board[0].size();

        vector<vector<int>> tracked ( rows, vector<int> ( cols, 0 ));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (trackWord(board, word, "", i, j, tracked)) return true;
            }
        }

        return false;
    }
};
// @lc code=end

