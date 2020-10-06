/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
 

Note:

The tree will have between 1 and 1000 nodes.
Each node's value will be between 0 and 1000.
*/
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
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            deque<vector<int>> tmp;
            vector<vector<int>> result;
            if (!root) {
                return result;
            }
            tmp.push_back({});
            deque<P> queue;
            queue.push_back({root, tmp.begin()});
            while (!queue.empty()) {
                sort(queue.begin(), queue.end(), [](P l, P r){
                        if(l.second != r.second) {
                            return l.second<r.second;
                        }
                        return l.first->val < r.first->val;
                        });
                int size = queue.size();
                for(; size!=0; size--) {
                    auto cur = queue.front();
                    queue.pop_front();
                    auto node = cur.first;
                    cur.second->push_back(node->val);
                    if (node->left) {
                        if (cur.second == tmp.begin()) {
                            tmp.push_front({});
                        }
                        queue.push_back({node->left, cur.second-1});
                    }
                    if (node->right) {
                        if (cur.second == tmp.end()-1) {
                            tmp.push_back({});
                        }
                        queue.push_back({node->right, cur.second+1});
                    }
                }
            }
            result.reserve(tmp.size());
            copy(MI(tmp.begin()), MI(tmp.end()), back_inserter(result));
            return result;
        }
    private:
        using I = deque<vector<int>>::iterator;
        using P = pair<TreeNode*, I>;
        using MI = move_iterator<I>;
};

/*
一开始理解错了题目，以为对每个vertical内部排个序就好了
If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

后来思路是层序遍历，使用deque记录vertical vector，在需要的时候push_front/push_back节点。这里比较tricky的是，因为需要对每层按照x轴排序，不能在一开始判断，只能在处理每个节点的时候判断是是否需要push_front/push_back。

比较精练的答案是直接用map来记录，比deque好处理多了。使用map+set，不需要自己做排序。
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return v;
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            set<pair<int,int>> st;
            int k = q.size();
            for(int i = 0; i<k; i++){
                TreeNode* node = q.front().first;int d = q.front().second;q.pop();
                st.insert({d,node->val});
                if(node->left)q.push({node->left, d-1});
                if(node->right)q.push({node->right, d+1});
            }
            for(auto c: st) mp[c.first].push_back(c.second);
        }
        for(auto c: mp)
            v.push_back(c.second);
        return v;
    }
};
*/

