/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (37.36%)
 * Likes:    1698
 * Dislikes: 141
 * Total Accepted:    177K
 * Total Submissions: 473.1K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 *
 * Example 1:
 *
 *
 * Input: "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: " 2-1 + 2 "
 * Output: 3
 *
 * Example 3:
 *
 *
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 *
 *
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 *
 *
 */

#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    void consume_space(const char* &ch) {
        while (*ch == ' ') {
            ++ch;
        }
    }
    int consume_int(const char* &ch) {
        char *end;
        int val = strtol(ch, &end, 10);
        ch = end;
        return val;
    }
    int consume(const char* & ch) {
        int left = 0;
        int right = 0;
        char op;
        while (*ch != '\0' && *ch != ')') {
            switch (*ch) {
            case '(':
                ++ch;
                left = consume(ch);
                break;
            case '+': case '-':
                op = *ch;
                ++ch;
                consume_space(ch);
                if (*ch == '(') {
                    ++ch;
                    right = consume(ch);
                } else {
                    right = consume_int(ch);
                }
                left = op == '+' ? left + right : left - right;
                break;
            case ' ':
                consume_space(ch);
                break;
            default:
                left = consume_int(ch);
            }
        }
        if (*ch == ')') {
            ++ch;
        }
        return left;
    }
    int calculate(string s) {
        const char* sch = s.c_str();
        return consume(sch);
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    Solution s;
    printf("%d\n", s.calculate(argv[1]));
    return 0;
}

/* XXX 又简洁又快的答案
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = 10 * num + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
             } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
*/

