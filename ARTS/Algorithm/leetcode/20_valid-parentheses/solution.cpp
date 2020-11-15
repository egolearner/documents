/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.25%)
 * Likes:    5852
 * Dislikes: 244
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: s = "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: s = "{[]}"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool match(char a, char b) {
        return (a=='(' && b==')') || (a=='['&&b==']') || (a=='{'&&b=='}');
    }
    bool is_open(char a) {
        return a=='(' || a=='[' || a=='{';
    }
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (is_open(c)) {
                st.push(c);
            } else {
                if(st.empty() || !match(st.top(), c)) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

