/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        size_t ai = 0, bi = 0;
        while (ai < A.size() && bi < B.size()) {
            auto& a = A[ai];
            auto& b = B[bi];
            if (a[0] > b[1]) {
                bi++;
                continue;
            } else if (b[0] > a[1]) {
                ai++;
                continue;
            } else if (a[0] <= b[0]) {
                if (a[1] <= b[1]) {
                    result.emplace_back({b[0], a[1]});
                    ai++;
                } else {
                    result.emplace_back({b[0], b[1]});
                    bi++;
                }
            } else {
                if (a[1] >= b[1]) {
                    result.emplace_back({a[0], b[1]});
                    bi++;
                } else {
                    result.emplace_back({a[0], a[1]});
                    ai++;
                }
            }
        }
        return result;
    }
};
/*
题解更加精练
int lo = Math.max(A[i][0], B[j][0]);
int hi = Math.min(A[i][1], B[j][1]);
if (lo <= hi)
  ans.add(new int[]{lo, hi});

// Remove the interval with the smallest endpoint
if (A[i][1] < B[j][1])
  i++;
else
  j++;
*/
