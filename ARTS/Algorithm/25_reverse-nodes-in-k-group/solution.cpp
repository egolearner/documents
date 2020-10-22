/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (43.07%)
 * Likes:    2782
 * Dislikes: 374
 * Total Accepted:    297.5K
 * Total Submissions: 688.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 *
 * Follow up:
 *
 *
 * Could you solve the problem in O(1) extra memory space?
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1], k = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode dummy, *cur = &dummy;
        ListNode* prev = nullptr, *start, *next = nullptr;
        int cnt = 0;
        for (; head; head = next) {
            ++cnt;
            next = head->next;
            head->next = prev;
            prev = head;
            if (cnt == 1) {
                start = head;
            } else if (cnt == k) {
                cur->next = head;
                cur = start;
                cnt = 0;
                prev = start = nullptr;
            }
        }
        if (cnt) {
            auto nstart = prev;
            auto ncur = nstart;
            prev = nullptr;
            for (ListNode* nnext; ncur; ncur = nnext) {
                nnext = ncur->next;
                ncur->next = prev;
                prev = ncur;
            }
            cur->next = prev;
            cur = nstart;
        }
        cur->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end

/* XXX 递归解法，严格来说不算O(1) space
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(head == NULL or head->next == NULL)
            return head;

        ListNode* tmp = head;
        int len = 0;
        while(len < k and tmp)
            tmp = tmp->next, len++;

        if(len < k)
            return head;

        ListNode* prev = head, *cur = prev->next, *nxt = cur->next, *grpHead = head;

        for(int i=0 ; i<k-1 ; i++)
        {
            cur->next = prev;
            prev = cur;
            cur = nxt;
            if(nxt)
                nxt = nxt->next;
            else
                break;
        }

        grpHead->next = reverseKGroup(cur, k);
        return prev;
    }
};
*/
