/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (39.90%)
 * Likes:    1815
 * Dislikes: 188
 * Total Accepted:    275.2K
 * Total Submissions: 688.9K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 *
 *
 * Follow up:
 *
 *
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // XXX 参考116的思路，为什么不如下面的思路快？
    Node* connect(Node* root) {
        Node* node = root;
        while (node != nullptr) {
            while (node && !node->left && !node->right) {
                node = node->next;
            }
            if (!node) {
                break;
            }
            auto nlevel = node->left ? node->left : node->right;
            auto prev = nlevel;
            if (node->left && node->right) {
                prev->next = node->right;
                prev = node->right;
            }
            for (node = node->next; node; node = node->next) {
                if (!node->left && !node->right) {
                    continue;
                }
                if (node->left) {
                    prev->next = node->left;
                    prev = prev->next;
                }
                if (node->right) {
                    prev->next = node->right;
                    prev = prev->next;
                }
            }
            node = nlevel;
        }
        return root;
    }
};

// @lc code=end
class Solution {
public:
    Node* levelMargin(Node* root, int height, int cur, bool left) {
        if (!root) {
            return nullptr;
        }
        if (cur == height) {
            return root;
        }
        Node* can = nullptr;
        if (left) {
            can = levelMargin(root->left, height, cur + 1, left);
        } else {
            can = levelMargin(root->right, height, cur + 1, left);
        }
        if (!can) {
            if (left) {
                can = levelMargin(root->right, height, cur + 1, left);
            } else {
                can = levelMargin(root->left, height, cur + 1, left);
            }
        }
        return can;
    }
    Node* connect(Node* root) {
        if (root) {
            connect(root->left);
            connect(root->right);
            for(int level = 1; true; level++) {
                auto left = levelMargin(root->left, level, 1, false);
                auto right = levelMargin(root->right, level, 1, true);
                if (left && right) {
                    left->next = right;
                } else {
                    break;
                }
            }
        }
        return root;
    }
};

/* XXX 加个dummy，精简很多
class Solution {
public:
    Node* connect(Node* root)
    {
        Node* ret_root = root;
        Node* dummy = new Node(0);
        Node* curr;
        while(root)
        {
            curr = dummy;
            while(root)
            {
                if(root->left)
                {
                    curr->next = root->left;
                    curr = curr->next;
                }
                if(root->right)
                {
                    curr->next = root->right;
                    curr = curr->next;
                }
                root = root->next;
            }
            root = dummy->next;
            dummy->next = NULL;
        }
        return ret_root;
    }
};
*/