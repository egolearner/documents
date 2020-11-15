/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (53.36%)
 * Likes:    1646
 * Dislikes: 87
 * Total Accepted:    130.8K
 * Total Submissions: 245.1K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is converting a data structure or object into a sequence of
 * bits so that it can be stored in a file or memory buffer, or transmitted
 * across a network connection link to be reconstructed later in the same or
 * another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You need to ensure that a binary search tree can be serialized to a
 * string, and this string can be deserialized to the original tree structure.
 *
 * The encoded string should be as compact as possible.
 *
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: [2,1,3]
 * Example 2:
 * Input: root = []
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The input tree is guaranteed to be a binary search tree.
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
    void inorder(TreeNode* n, string* res) {
        if (!n) {
            return;
        }
        res->append(to_string(n->val));
        res->append(",");
        inorder(n->left, res);
        inorder(n->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        inorder(root, &res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<int> vals;
        const char* begin = data.c_str();
        const char* end = begin + data.size();
        char *tmp;
        while (begin < end) {
            int val = strtol(begin, &tmp, 10);
            vals.push_back(val);
            begin = tmp+1;
        }
        return recover(vals.begin(), vals.end());
    }
    TreeNode* recover(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) {
            return nullptr;
        }
        auto large = find_if(begin+1, end, [&](int val) {
            return val > *begin;
        });
        return new TreeNode(*begin, recover(begin+1, large), recover(large, end));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end


/*
1. 使用sizeof(int)来存储，不转字符串
2. 遍历的时候根据最大最小值确定子树，不需要完整扫描
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorderDFS(root, order);
        return order;
    }

    inline void inorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }

    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.

        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;

        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};
*/