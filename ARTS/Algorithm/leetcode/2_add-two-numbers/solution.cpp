/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int carry = 0;
        while (l1 && l2) {
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            value = value % 10;
            tail->next = new ListNode(value);

            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* remain = l1 ? l1 : l2;
        while (remain) {
            // XXX 2
            int value = remain->val + carry;
            carry = value / 10;
            value = value % 10;
            tail->next = new ListNode(value);

            tail = tail->next;
            remain = remain->next;
        }
        //XXX 1 忘记进位
        if (carry) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return dummy.next;
    }
};
