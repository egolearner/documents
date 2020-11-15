/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (33.07%)
 * Likes:    928
 * Dislikes: 1933
 * Total Accepted:    226.7K
 * Total Submissions: 684.8K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 *
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 *
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 *
 *
 * Example 2:
 *
 *
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 *
 *
 * Example 3:
 *
 *
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 *
 *
 * Example 4:
 *
 *
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 *
 *
 * Example 5:
 *
 *
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 *
 *
 * Example 6:
 *
 *
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 *
 *
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<int> slash;
        int size = 0;
        auto is_end = [&](int i) {
            return path[i] == '/' || path[i] == '\0';
        };
        for (size_t i = 0; i < path.size(); ) {
            char c = path[i];
            if (c == '/') {
                if (size == 0 || path[size-1] != '/') {
                    path[size++] = c;
                    slash.push(size);
                }
                if (path.compare(i, 2, "//") == 0) {
                    i += 1;
                } else if (path.compare(i, 3, "/..") == 0 && is_end(i+3)) {
                    if (slash.size() > 1) {
                        slash.pop();
                        size = slash.top();
                    } else {
                        size = slash.top();
                    }
                    i += 3;
                } else if (path.compare(i, 2, "/.") == 0 && is_end(i+2)) {
                    i += 2;
                } else {
                    i++;
                }
            } else {
                i++;
                path[size++] = c;
            }
        }
        if (path[size-1] == '/' && slash.size() > 1) {
            size--;
        }
        path.resize(size);
        return path;
    }
};
// @lc code=end

/* XXX 几种情况没处理好
/.
/...
*/

/* XXX 使用getline做分割
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp;
        vector<string> s;

        while(getline(ss, temp, '/')){
            if(temp == ".."){
                if(!s.empty()) s.pop_back();
            }
            else if(temp == "." || temp == "") continue;
            else{
                s.push_back(temp);
            }
        }

        string ans;
        for(string& t: s){
            ans += "/" + t;
        }
        if(ans == "") return {'/'};
        return move(ans);

    }
};
*/

