/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (28.73%)
 * Likes:    4043
 * Dislikes: 148
 * Total Accepted:    313.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 *
 * Example 3:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int merge(vector<pair<int,int>>& indices) {
        while (indices.size() > 1) {
            int sz = indices.size();
            if (indices.back().first == indices[sz - 2].second + 1) {
                indices[sz - 2].second = indices.back().second;
                indices.pop_back();
            } else if (indices.back().first < indices[sz-2].first) {
                indices[sz-2] = indices.back();
                indices.pop_back();
            } else {
                break;
            }
        }
        return indices.back().second-indices.back().first+1;
    }
    int longestValidParentheses(string s) {
        vector<pair<int,int>> indices;
        vector<pair<int,char>> st;
        int ml = 0;
        for (size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push_back({i, c});
            } else {
                if (!st.empty() && st.back().second == '(') {
                    auto start = st.back().first;
                    auto end = i;
                    indices.push_back({start, end});
                    ml = max(ml, merge(indices));
                    st.pop_back();
                } else {
                    st.clear();
                    indices.clear();
                }
            }
        }
        return ml;
    }
};
// @lc code=end

/* XXX 简洁很多
class Solution {
public:
    int longestValidParentheses(string s) {

       stack<int> st;
        st.push(-1);
       int i,c=0;
        for(i=0;i<s.length();i++){
            if(s[i]== '(') st.push(i);
            else {
               if(!st.empty()) st.pop();
                if(!st.empty()){
                    c=max(c,i-st.top());
                }
                else st.push(i);
            }
        }
        return c;
    }
};
*/

