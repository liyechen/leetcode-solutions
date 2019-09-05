/*
 * Created by liyechen
 * Time 2019/09/05 11:40
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        std::istringstream iss(s);
        std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
        if (results.size() == 0) return 0;
        return results[results.size() - 1].size();
    }
};
