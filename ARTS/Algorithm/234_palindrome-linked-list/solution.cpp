/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (39.72%)
 * Likes:    3899
 * Dislikes: 388
 * Total Accepted:    490.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head, *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            auto next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        if (fast) {
            slow = slow->next;
        }
        for (; prev; prev = prev->next, slow=slow->next) {
            if (prev->val != slow->val) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

