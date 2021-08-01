/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 *
 * https://leetcode.com/problems/mini-parser/description/
 *
 * algorithms
 * Medium (34.81%)
 * Likes:    307
 * Dislikes: 1012
 * Total Accepted:    44.1K
 * Total Submissions: 126.1K
 * Testcase Example:  '"324"'
 *
 * Given a string s represents the serialization of a nested list, implement a
 * parser to deserialize it and return the deserialized NestedInteger.
 *
 * Each element is either an integer or a list whose elements may also be
 * integers or other lists.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "324"
 * Output: 324
 * Explanation: You should return a NestedInteger object which contains a
 * single integer 324.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "[123,[456,[789]]]"
 * Output: [123,[456,[789]]]
 * Explanation: Return a NestedInteger object containing a nested list with 2
 * elements:
 * 1. An integer containing value 123.
 * 2. A nested list containing two elements:
 * ⁠   i.  An integer containing value 456.
 * ⁠   ii. A nested list with one element:
 * ⁠        a. An integer containing value 789
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * s consists of digits, square brackets "[]", negative sign '-', and commas
 * ','.
 * s is the serialization of valid NestedInteger.
 *
 *
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        const char *c = s.c_str();
        char *end = nullptr;
        stack<NestedInteger> st;
        while (*c) {
            if (*c == '[') {
                st.push(NestedInteger());
                ++c;
                continue;
            } else if (*c == ']') {
                if (st.size() > 1) {
                    NestedInteger ni = st.top();
                    st.pop();
                    st.top().add(ni);
                }
                ++c;
                continue;
            } else if (*c == ',') {
                ++c;
                continue;
            } else {
                int i = strtol(c, &end, 10);
                c = end;
                if (st.empty()) {
                    st.push(NestedInteger(i));
                } else {
                    st.top().add(NestedInteger(i));
                }
            }
        }
        return st.top();
    }
};
// @lc code=end

