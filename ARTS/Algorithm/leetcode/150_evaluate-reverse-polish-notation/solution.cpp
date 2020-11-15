/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (36.88%)
 * Likes:    1245
 * Dislikes: 492
 * Total Accepted:    249.7K
 * Total Submissions: 674.2K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 * Note:
 *
 *
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 *
 *
 * Example 1:
 *
 *
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 *
 * Example 2:
 *
 *
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 *
 * Example 3:
 *
 *
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation:
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 */

#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (const auto& t : tokens) {
            // XXX 没有考虑到负数
            if (isdigit(t[0]) || t.length() != 1) {
                st.push(stol(t));
                continue;
            }
            long s = st.top();
            st.pop();
            long f = st.top();
            st.pop();
            long n;
            switch (t[0]) {
                case '+':
                n = f + s;
                break;
                case '-':
                n = f - s;
                break;
                case '*':
                n = f * s;
                break;
                case '/':
                n = f / s;
                break;
            }
            st.push(n);
        }
        return (int)st.top();
    }
};
// @lc code=end

int main() {
    vector<string> v{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    cout << s.evalRPN(v) << endl;
}

