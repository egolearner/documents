/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        for (auto node : root->children) {
            int cur_depth = maxDepth(node);
            if (cur_depth > depth) {
                depth = cur_depth;
            }
        }
        return depth+1;
    }
};
