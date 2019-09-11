/*
 * Created by liyechen
 * Time 2019/09/10 14:15
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 0) return "";
        stack<string> dirs;
        bool inSlashMod = false;
        string tmp = "";
        for (unsigned int i = 0; i < path.size(); i++) {
            if (inSlashMod) {
                if (path[i] != '/') {
                    tmp = tmp + path[i];
                    inSlashMod = false;
                }
            } else {
                if (path[i] == '/') {
                    inSlashMod = true;
                    if (tmp != ".") {
                        if (tmp != "..") {
                            dirs.push(tmp);
                        } else {
                            if (!dirs.empty())
                                dirs.pop();
                        }
                    }
                    tmp = "";
                } else {
                    tmp = tmp + path[i];
                }
            }
        }
        if (tmp != "") {
            if (tmp != ".") {
                if (tmp != "..") {
                    dirs.push(tmp);
                } else {
                    if (!dirs.empty())
                        dirs.pop();
                }
            }
        }
        string ans = "";
        while (!dirs.empty()) {
            string cur = dirs.top();
            dirs.pop();
            if (cur != "") {
                ans = "/" + cur + ans;
            }
        }
        if (ans == "") ans = "/";
        return ans;
    }
};
