/*
 * Created by liyechen
 * Time 2020/04/22 17:59
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.size(), lt = t.size();
        int dp[ls + 1][lt + 1];
        
        // (s[0...i], "") = 1
        // dp[0...ls][0] = 1
        for (int i = 0; i <= ls; i++) {
            dp[i][0] = 1;
        }
        
        // (s[0], t[1...lt]) = 0
        for (int j = 1; j <= lt; j++) {
            dp[0][j] = 0;
        }
        
        
        for (int j = 1; j <= lt; j++) {
            for (int i = 1; i <= ls; i++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[ls][lt];
    }
};
