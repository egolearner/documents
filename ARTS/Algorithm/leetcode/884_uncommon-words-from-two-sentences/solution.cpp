/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 *
 * https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
 *
 * algorithms
 * Easy (63.63%)
 * Likes:    572
 * Dislikes: 102
 * Total Accepted:    71.4K
 * Total Submissions: 111.2K
 * Testcase Example:  '"this apple is sweet"\n"this apple is sour"'
 *
 * We are given two sentences A and B.  (A sentence is a string of space
 * separated words.  Each word consists only of lowercase letters.)
 *
 * A word is uncommon if it appears exactly once in one of the sentences, and
 * does not appear in the other sentence.
 *
 * Return a list of all uncommon words. 
 *
 * You may return the list in any order.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = "this apple is sweet", B = "this apple is sour"
 * Output: ["sweet","sour"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = "apple apple", B = "banana"
 * Output: ["banana"]
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 200
 * 0 <= B.length <= 200
 * A and B both contain only spaces and lowercase letters.
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        set<string> a, b, alla, allb;
        istringstream ia(A), ib(B);
        string line;
        while (getline(ia, line, ' ')) {
            auto it = alla.insert(line);
            if (it.second) {
                a.insert(line);
            } else {
                a.erase(line);
            }
        }
        while (getline(ib, line, ' ')) {
            auto it = allb.insert(line);
            if (it.second) {
                b.insert(line);
            } else {
                b.erase(line);
            }
        }
        vector<string> nocommon, res;
        set_symmetric_difference(alla.begin(), alla.end(), allb.begin(), allb.end(), back_inserter(nocommon));
        set_intersection(a.begin(), a.end(), nocommon.begin(), nocommon.end(), back_inserter(res));
        set_intersection(b.begin(), b.end(), nocommon.begin(), nocommon.end(), back_inserter(res));
        return res;
    }
};
// @lc code=end

/* XXX 好蠢
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        istringstream iss(A + " " + B);
        while (iss >> A) count[A]++;
        vector<string> res;
        for (auto w: count)
            if (w.second == 1)
                res.push_back(w.first);
        return res;
    }
*/

