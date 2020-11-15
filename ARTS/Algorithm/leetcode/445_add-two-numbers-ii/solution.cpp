/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (55.04%)
 * Likes:    1722
 * Dislikes: 168
 * Total Accepted:    180K
 * Total Submissions: 326.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head = nullptr;
        while (!s1.empty() || !s2.empty()) {
            if (!s2.empty()) {
                carry += s2.top()->val;
                s2.pop();
            }
            if (!s1.empty()) {
                carry += s1.top()->val;
                s1.pop();
            }
            head = new ListNode(carry%10, head);
            carry = carry > 9 ? 1 : 0;
        }
        if (carry) {
            head = new ListNode(carry, head);
        }
        return head;
    }
};
// @lc code=end


/* XXX 不如递归求解快，而且使用stack某种意义上也算反转。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // find the lenght of both list
        int len1 = getLenght(l1);
        int len2 = getLenght(l2);
        int carry = 0;
        ListNode* L, *S;
        if(len1 > len2) {
            L = l1;
            S = l2;
        }else {
             L = l2;
            S = l1;
        }

        addTwoNumbers(L, S, abs(len1-len2), carry);

        if(carry) {
            return new ListNode(1, L);
        }

        return L;
    }
    int getLenght(ListNode* l) {
        int len = 0;
        while(l) {
            len += 1;
            l = l->next;
        }
        return len;
    }

    ListNode* addTwoNumbers(ListNode* L, ListNode* S, int len, int& carry) {
        if(len)
            addTwoNumbers(L->next, S, len-1, carry);
        else
            return addTwoNumbers(L, S, carry);

        if(carry)
        {
            int sum = L->val + carry;
            if(sum > 9) carry = 1;
            else carry = 0;

            L->val = (sum>9) ? sum%10 : sum;
        }

        return nullptr;

    }
     ListNode* addTwoNumbers(ListNode* L, ListNode* S, int& carry) {

        if(L == nullptr) return nullptr;

        addTwoNumbers(L->next, S->next, carry);

        int sum = L->val + S->val + carry;
        if(sum > 9) carry = 1;
        else carry = 0;

        L->val = (sum>9) ? sum%10 : sum;

        return {};

    }
};
*/