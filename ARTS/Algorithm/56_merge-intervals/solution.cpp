/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]

*/
class Solution {
public:
    bool isInter(vector<int>& a, vector<int>& b) {
        return !(a[1]<b[0] || a[0]>b[1]);
    }
    void merge(vector<int>& a, const vector<int>& b) {
        a[0] = min(a[0], b[0]);
        a[1] = max(a[1], b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            return res;
        }
        res.reserve(intervals.size());
        res.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++) {
            auto& ii = intervals[i];
            if (isInter(res.back(), ii)) {
                merge(res.back(), ii);
            } else {
                res.push_back(ii);
            }
        }
        return res;
    }
};
