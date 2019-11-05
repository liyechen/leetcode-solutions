/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
    
    bool isValid(const string& s, const string& t, int left, int right, unordered_map<char, int> tChars) {
        string subStr = s.substr(left, right - left + 1);
        for (const char& c : subStr) {
            if (tChars.find(c) != tChars.end()) {
                tChars.insert_or_assign(c, tChars.at(c) - 1);
            }
        }
        for (auto iter = tChars.begin(); iter != tChars.end(); iter++) {
            if (iter->second > 0) return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (s == "") return "";
        unordered_map<char, int> tChars;
        for (const char& c : t) {
            if (tChars.find(c) != tChars.end()) {
                int numberOfC = tChars.at(c);
                tChars.insert_or_assign(c, numberOfC + 1);
            } else {
                tChars.insert_or_assign(c, 1);
            }
        }
        int ansLeft = 0, length = n;
        int left = 0, right = 0;
        bool find = false;
        int counter = t.size();
        for (right = 0; right < n; right++) {
            char c = s[right];
            if (tChars.find(c) != tChars.end()) {
                if (tChars.at(c) > 0) counter--;
                tChars.insert_or_assign(c, tChars.at(c) - 1);
            }
            
            while(counter == 0) {
                find = true;
                if (length > right - left + 1) {
                    ansLeft = left;
                    length = right - left + 1;
                }
                char lC = s[left];
                if (tChars.find(lC) != tChars.end()) {
                    if (tChars.at(lC) >= 0) counter++;
                    tChars.insert_or_assign(lC, tChars.at(lC) + 1);
                }
                left++;
            }
            // while (isValid(s, t, left, right, tChars)) {
            //     find = true;
            //     if (length > right - left + 1) {
            //         ansLeft = left;
            //         length = right - left + 1;
            //     }
            //     left++;
            // }
        }

        if (find) return s.substr(ansLeft, length);
        return "";
    }
};
// @lc code=end

