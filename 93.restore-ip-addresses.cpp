/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {

    void track(vector<string>& ipList, string ip, string restored, int pos, int count) {
        if (count > 4) return;
        if (count == 4 && pos == ip.size()) {
            ipList.push_back(restored);
            return;
        }

        int length = ip[pos] == '0' ? 2 : 4;

        for (int i = 1; i < length; i++) {
            if (i + pos > ip.size()) break;
            string sub = ip.substr(pos, i);
            int ipv4SubAdd = stoi(sub);
            if (ipv4SubAdd >= 0 && ipv4SubAdd <= 255) {
                string nextRestored = restored + sub + (count == 3 ? "" : ".");
                track(ipList, ip, nextRestored, pos + i, count + 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ipList;
        track(ipList, s, "", 0, 0);
        return ipList;
    }
};
// @lc code=end

