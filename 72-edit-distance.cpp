/*
 * Created by liyechen
 * Time 2019/09/11 09:45
 * Email <gliyechen@hotmail.com>
 */

// DP

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length() + 1;
        int len2 = word2.length() + 1;
        
        // indicate dp for transfer from word1[0...i] to word2[0...j]
        int dp[len1][len2] = { INT_MAX };
        
        // int dp[0...len1][0]
        for (int i = 0; i < len1; i++) {
            dp[i][0] = i;
        }
        
        // init dp[0][0...len2]
        for (int i = 0; i < len2; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        
        return dp[len1 - 1][len2 - 1];
    }
};
