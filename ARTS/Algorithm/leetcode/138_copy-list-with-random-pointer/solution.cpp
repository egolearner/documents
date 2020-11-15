/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (37.76%)
 * Likes:    3946
 * Dislikes: 725
 * Total Accepted:    459.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 * The Linked List is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 *
 *
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) where random
 * pointer points to, or null if it does not point to any node.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 *
 *
 * Example 4:
 *
 *
 * Input: head = []
 * Output: []
 * Explanation: Given linked list is empty (null pointer), so return null.
 *
 *
 *
 * Constraints:
 *
 *
 * -10000 <= Node.val <= 10000
 * Node.random is null or pointing to a node in the linked list.
 * The number of nodes will not exceed 1000.
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* cur = head;
        while (cur) {
            Node* n = new Node(cur->val);
            n->next = cur->next;
            cur->next = n;
            cur = n->next;
        }
        for (cur = head; cur; ) {
            auto n = cur->next;
            if (cur->random) {
                n->random = cur->random->next;
            }
            cur = n->next;
        }
        Node dummy0(0), dummy1(0), *cur0 = &dummy0, *cur1 = &dummy1;
        for (cur = head; cur; ) {
            cur0->next = cur;
            cur1->next = cur->next;
            cur0 = cur;
            cur1 = cur1->next;
            cur->next = cur1->next;
            cur = cur->next;
        }
        return dummy1.next;
    }
};
// @lc code=end

/* Hash表记录
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> m{};
        Node* new_head = new Node(-1);
        Node* traverse = new_head;
        Node* curr = head;
        while (curr) {
            traverse->val = curr->val;
            m[curr] = traverse;
            if (curr->next) {
                traverse->next = new Node(-1);
            }
            traverse = traverse->next;
            curr = curr->next;
        }
        curr = head;
        traverse = new_head;
        while (curr) {
            if (curr->random) {
                traverse->random = m[curr->random];
            }
            curr = curr->next;
            traverse = traverse->next;
        }
        return new_head;
    }
};
*/
