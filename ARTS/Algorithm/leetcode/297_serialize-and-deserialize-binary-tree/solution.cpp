/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (48.32%)
 * Likes:    3487
 * Dislikes: 168
 * Total Accepted:    366.6K
 * Total Submissions: 758.4K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    const char COMMA = ',';

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool any = false;
            for (int size = q.size(); size; --size) {
                auto n = q.front();
                q.pop();
                if (n) {
                    res.append(to_string(n->val));
                    q.push(n->left);
                    q.push(n->right);
                    if (n->left || n->right) {
                        any = true;
                    }
                }
                res.append(1, COMMA);
            }
            if (!any) {
                break;
            }
        }
        while (res[res.size() - 1] == COMMA) {
            res.resize(res.size() - 1);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        const char *begin = data.c_str();
        const char* end = begin + data.size();
        char *tmp;
        TreeNode* root = new TreeNode(strtol(begin, &tmp, 10));
        begin = tmp+1;
        queue<TreeNode*> q;
        q.push(root);
        auto consume = [&]() {
            if (*begin != COMMA && *begin != '\0') {
                auto n = new TreeNode(strtol(begin, &tmp, 10));
                begin = tmp + 1;
                q.push(n);
                return n;
            }
            begin += 1;
            return (TreeNode*)NULL;
        };
        while (begin < end) {
            auto n = q.front();
            q.pop();
            n->left = consume();
            n->right = consume();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

