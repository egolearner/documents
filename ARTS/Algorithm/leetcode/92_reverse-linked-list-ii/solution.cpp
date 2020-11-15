/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (39.48%)
 * Likes:    2820
 * Dislikes: 155
 * Total Accepted:    297.6K
 * Total Submissions: 753.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy;
        ListNode* cur = &dummy;
        ListNode* tail = nullptr;
        ListNode* prev = nullptr;
        for (int i = 1; head; i++) {
            if (i == m) {
                // XXX 没有处理m==n的情况
                if (m == n) {
                    cur->next = head;
                    cur = head;
                    head = head->next;
                } else {
                    tail = head;
                    head = head->next;
                    tail->next = nullptr;
                    prev = tail;
                }
            } else if (i == n) {
                auto next = head->next;
                head->next = prev;
                cur->next = head;
                cur = tail;
                head = next;
            } else if (i > m && i < n) {
                auto next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            } else {
                cur->next = head;
                cur = head;
                head = head->next;
            }
        }
        return dummy.next;
    }

    ListNode* reverseBetweenRefined(ListNode* head, int m, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = &dummy;
        for (int i = 1; i < m; i++) {
            cur = cur->next;
        }
        ListNode* tail = cur->next;
        auto nn = tail->next;
        auto pre = tail;
        for (int i = m; i < n; i++) {
            auto next = nn->next;
            nn->next = pre;
            pre = nn;
            nn = next;
        }
        cur->next = pre;
        tail->next = nn;
        return dummy.next;
    }
};
// @lc code=end


/* XXX 之前和之后的元素可以快速通过
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *start = &dummy, *lock, *tmp;

        for(int i=1; i<m; i++) start = start->next;

        // lock永远指向第i个元素
        // start指向第m-1个元素
        lock = start->next;
        for(int i=m; i<n; i++) {
            tmp = lock->next;
            lock->next = tmp->next;
            tmp->next = start->next;
            start->next = tmp;
        }

        return dummy.next;
    }
};
*/