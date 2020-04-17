/*
 * Created by liyechen
 * Time 2020/04/17 17:41
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        // f(n) = f(0) * f(n - 1) + f(1) * f(n - 2) + ... + f(n - 1) * f(0) 
        // f(0) = 1, f(1) = 1; f(2) = 2;
        int ans = 0;
        int recur = 0;
        while (recur <= n - 1) {
            ans += numTrees(recur) * numTrees(n - recur - 1);
            recur++;
        }
        return ans;
    }
};
