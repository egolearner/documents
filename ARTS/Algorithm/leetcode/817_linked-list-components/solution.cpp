/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
 *
 * https://leetcode.com/problems/linked-list-components/description/
 *
 * algorithms
 * Medium (57.30%)
 * Likes:    404
 * Dislikes: 1142
 * Total Accepted:    47.6K
 * Total Submissions: 83.1K
 * Testcase Example:  '[0,1,2,3]\n[0,1,3]'
 *
 * We are given head, the head node of a linked list containing unique integer
 * values.
 *
 * We are also given the list G, a subset of the values in the linked list.
 *
 * Return the number of connected components in G, where two values are
 * connected if they appear consecutively in the linked list.
 *
 * Example 1:
 *
 *
 * Input:
 * head: 0->1->2->3
 * G = [0, 1, 3]
 * Output: 2
 * Explanation:
 * 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * head: 0->1->2->3->4
 * G = [0, 3, 1, 4]
 * Output: 2
 * Explanation:
 * 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the
 * two connected components.
 *
 *
 * Note:
 *
 *
 * If N is the length of the linked list given by head, 1 <= N <= 10000.
 * The value of each node in the linked list will be in the range [0, N -
 * 1].
 * 1 <= G.length <= 10000.
 * G is a subset of all values in the linked list.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (!head) {
            return 0;
        }
        unordered_set<int> numbers{G.begin(), G.end()};
        bool connected = false;
        int part = 0;
        while (head) {
            if (numbers.count(head->val)) {
                connected = true;
            } else {
                if (connected) {
                    ++part;
                    connected = false;
                }
            }
            head = head->next;
        }
        part += connected;
        return part;
    }
};
// @lc code=end

