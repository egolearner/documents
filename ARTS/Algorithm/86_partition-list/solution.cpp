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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return NULL;
        }
        ListNode dummy(0);
        ListNode* small = &dummy;
        ListNode bdummy(0);
        ListNode* big = &bdummy;
        while (head) {
            ListNode* next = head->next;
            if (head->val < x) {
                small->next = head;
                small = head;
            } else {
                big->next = head;
                big = head;
            }
            head = next;
        }
        if (big != &bdummy) {
            big->next = NULL;
        }
        if (small != &dummy) {
            small->next = bdummy.next;
            return dummy.next;
        }
        return bdummy.next;
    }
};
