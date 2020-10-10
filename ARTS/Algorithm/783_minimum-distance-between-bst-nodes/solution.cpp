/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    tuple<int, int, int> getMinMax(TreeNode* root) {
        int mini = root->val, maxi = root->val, diff = INT_MAX;
        if (root->left) {
            auto ls = getMinMax(root->left);
            diff = min({get<2>(ls), root->val-get<1>(ls), diff});
            if (diff == 1) {
                return make_tuple(mini, maxi, diff);
            }
            mini = get<0>(ls);
        }
        if (root->right) {
            auto rs = getMinMax(root->right);
            diff = min({get<2>(rs), get<0>(rs)-root->val, diff});
            if (diff == 1) {
                return make_tuple(mini, maxi, diff);
            }
            maxi = get<1>(rs);
        }
        return make_tuple(mini, maxi, diff);

    }
    int minDiffInBST(TreeNode* root) {
        if (!root) {
            return 0;
        }
        auto s = getMinMax(root);
        return get<2>(s);
    }
};

//XXX inorder遍历，正好转为有序，然后分别减前一个
