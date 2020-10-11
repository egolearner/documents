/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/
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
bool cmp(ListNode* first, ListNode* second) {
    if (first == nullptr) {
        return true;
    }
    if (second == nullptr) {
        return false;
    }
    return first->val > second->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* prev = &dummy;
        make_heap(lists.begin(), lists.end(), cmp);
        while (lists.size()>1) {
            pop_heap(lists.begin(), lists.end(), cmp);
            if (!lists.back()) {
                lists.pop_back();
                continue;
            }
            prev->next = lists.back();
            prev = prev->next;
            lists.back() = lists.back()->next;
            if (lists.back() == nullptr) {
                lists.pop_back();
            } else {
                push_heap(lists.begin(), lists.end(), cmp);
            }
        }
        if (lists.size() == 1) {
            prev->next = lists[0];
        }
        return dummy.next;
    }
};
/* XXX 堆方案不如divide-conquer快，空间复杂度也高
 In this post, Divide and Conquer approach is discussed. This approach doesn’t require extra space for heap and works in O(nk Log k)

It is known that merging of two linked lists can be done in O(n) time and O(1) space (For arrays O(n) space is required).

The idea is to pair up K lists and merge each pair in linear time using O(1) space.
After first cycle, K/2 lists are left each of size 2*N. After second cycle, K/4 lists are left each of size 4*N and so on.
Repeat the procedure until we have only one list left.
Below is the implementation of the above idea.

https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/
// The main function that takes an array of lists 
// arr[0..last] and generates the sorted output 
Node* mergeKLists(Node* arr[], int last) 
{ 
    // repeat until only one list is left 
    while (last != 0) { 
        int i = 0, j = last; 
  
        // (i, j) forms a pair 
        while (i < j) { 
            // merge List i with List j and store 
            // merged list in List i 
            arr[i] = SortedMerge(arr[i], arr[j]); 
  
            // consider next pair 
            i++, j--; 
  
            // If all pairs are merged, update last 
            if (i >= j) 
                last = j; 
        } 
    } 
  
    return arr[0]; 
}
*/
