/*
 * @lc app=leetcode id=1807 lang=cpp
 *
 * [1807] Evaluate the Bracket Pairs of a String
 *
 * https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/
 *
 * algorithms
 * Medium (66.37%)
 * Likes:    232
 * Dislikes: 23
 * Total Accepted:    15.2K
 * Total Submissions: 22.9K
 * Testcase Example:  '"(name)is(age)yearsold"\n[["name","bob"],["age","two"]]'
 *
 * You are given a string s that contains some bracket pairs, with each pair
 * containing a non-empty key.
 *
 *
 * For example, in the string "(name)is(age)yearsold", there are two bracket
 * pairs that contain the keys "name" and "age".
 *
 *
 * You know the values of a wide range of keys. This is represented by a 2D
 * string array knowledge where each knowledge[i] = [keyi, valuei] indicates
 * that key keyi has a value of valuei.
 *
 * You are tasked to evaluate all of the bracket pairs. When you evaluate a
 * bracket pair that contains some key keyi, you will:
 *
 *
 * Replace keyi and the bracket pair with the key's corresponding valuei.
 * If you do not know the value of the key, you will replace keyi and the
 * bracket pair with a question mark "?" (without the quotation marks).
 *
 *
 * Each key will appear at most once in your knowledge. There will not be any
 * nested brackets in s.
 *
 * Return the resulting string after evaluating all of the bracket pairs.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(name)is(age)yearsold", knowledge =
 * [["name","bob"],["age","two"]]
 * Output: "bobistwoyearsold"
 * Explanation:
 * The key "name" has a value of "bob", so replace "(name)" with "bob".
 * The key "age" has a value of "two", so replace "(age)" with "two".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "hi(name)", knowledge = [["a","b"]]
 * Output: "hi?"
 * Explanation: As you do not know the value of the key "name", replace
 * "(name)" with "?".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
 * Output: "yesyesyesaaa"
 * Explanation: The same key can appear multiple times.
 * The key "a" has a value of "yes", so replace all occurrences of "(a)" with
 * "yes".
 * Notice that the "a"s not in a bracket pair are not evaluated.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
 * Output: "ba"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * 0 <= knowledge.length <= 10^5
 * knowledge[i].length == 2
 * 1 <= keyi.length, valuei.length <= 10
 * s consists of lowercase English letters and round brackets '(' and ')'.
 * Every open bracket '(' in s will have a corresponding close bracket ')'.
 * The key in each bracket pair of s will be non-empty.
 * There will not be any nested bracket pairs in s.
 * keyi and valuei consist of lowercase English letters.
 * Each keyi in knowledge is unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    struct Node {
        Node* children[26]{};
        const string* value{};
        ~Node() {
            for (auto c : children) {
                if (c) delete c;
            }
        }
    };
    string evaluate(string s, vector<vector<string>>& knowledge) {
        root = new Node{};
        for (auto& kv : knowledge) {
            Node* cur = root;
            for (auto c : kv[0]) {
                if (!cur->children[c-'a']) {
                    cur->children[c-'a'] = new Node{};
                }
                cur = cur->children[c-'a'];
            }
            cur->value = &kv[1];
        }
        string res;
        bool is_in = false;
        Node* cur = root;
        for (auto c : s) {
            if (c == '(') {
                is_in = true;
                cur = root;
            } else if (c == ')') {
                is_in = false;
                if (cur && cur->value) {
                    res.append(*cur->value);
                } else {
                    res.push_back('?');
                }
            } else {
                if (is_in) {
                    if (cur) {
                        cur = cur->children[c-'a'];
                    }
                } else {
                    res.push_back(c);
                }
            }
        }
        delete root;
        return res;
    }
    Node* root;
};
// @lc code=end

