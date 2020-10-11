/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 105
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 105
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        res.reserve(intervals.size()+1);
        bool merged = false;
        for (auto&i : intervals) {
            if (!merged) {
                if (newInterval[0] < i[0]) {
                    res.push_back(newInterval);
                    merged = true;
                } else {
                    res.push_back(i);
                }
            }
            auto & target = merged ? i : newInterval;
            if (isInter(res.back(), target)) {
                merge(res.back(), target);
                merged = true;
            } else if (merged) {
                res.push_back(target);
            }
        }
        if (!merged) {
            res.push_back(newInterval);
        }
        return res;
    }
};
// XXX 题目没要求结果有序？
