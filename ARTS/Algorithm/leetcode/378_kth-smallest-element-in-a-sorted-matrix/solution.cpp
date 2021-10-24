/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (54.99%)
 * Likes:    3308
 * Dislikes: 175
 * Total Accepted:    240.6K
 * Total Submissions: 429K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns are sorted in
 * ascending order, return the k^th smallest element in the matrix.
 *
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= -10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-degreasing order.
 * 1 <= k <= n^2
 *
 *
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int ans = 0;
        while (low <= high) {
            int mid = low + (high-low)/2;
            int cnt = countLessOfMid(matrix, mid);
            if (cnt >= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
    int countLessOfMid(vector<vector<int>>& matrix, int mid) {
        int r = 0, c = matrix.size()-1;
        int cnt = 0;
        for (r = 0; r < matrix.size(); r++) {
            while (c >= 0 && matrix[r][c] > mid) {
                c--;
            }
            cnt += (c+1);
        }
        return cnt;
    }
    int kthSmallestHeap(vector<vector<int>>& matrix, int k) {
        using P = pair<int, int>;
        auto cmp = [&](P p1, P p2) {return matrix[p1.first][p1.second] >= matrix[p2.first][p2.second];};
        priority_queue<P, vector<P>, decltype(cmp)> min_heap(cmp);
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            min_heap.emplace(i, 0);
        }
        P ans;
        for (int pc = 0; pc < k; pc++) {
            ans = min_heap.top();
            min_heap.pop();
            if (ans.second+1 < n) {
                min_heap.emplace(ans.first, ans.second+1);
            }
        }
        return matrix[ans.first][ans.second];
    }
};
// @lc code=end


// XXX 参考 https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise