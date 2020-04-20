/*
 * Created by liyechen
 * Time 2020/04/20 14:17
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 + l2 != s3.size()) return false;
        bool dp[l1 + 1][l2 + 1];
        dp[0][0] = true;
        
        // dp[0][0] ~ dp[l1][0]
        for (int i = 1; i < l1 + 1; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        
        // dp[0][0] ~ dp[0][l2]
        for (int i = 1; i < l2 + 1; i++) {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }
        
        // dp[1][1] ~ dp[l1][l2] return dp[l1][l2] 
        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                dp[i][j] = (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1])) || (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));
            } 
        }
        
        return dp[l1][l2];
    }
};
