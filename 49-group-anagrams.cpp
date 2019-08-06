/*
 * Created by liyechen
 * Time 2019/08/06 16:24
 * Email <gliyechen@hotmail.com>
 */

// unordered_map

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> str_map;
        for (const string &str: strs) {
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            auto search_res = str_map.find(str_copy);
            if (search_res != str_map.end()) {
                ans[str_map[str_copy]].push_back(str);
            } else {
                int idx = ans.size();
                str_map.insert({ str_copy, idx });
                vector<string> new_vec;
                new_vec.push_back(str);
                ans.push_back(new_vec);
            }
        }
        return ans;
    }
};
