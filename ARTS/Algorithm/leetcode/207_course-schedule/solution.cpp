/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.45%)
 * Likes:    7058
 * Dislikes: 290
 * Total Accepted:    672.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pre_count(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto & pre : prerequisites) {
            pre_count[pre[1]]++;
            graph[pre[0]].push_back(pre[1]);
        }
        vector<int> cur_ready;
        for (size_t i = 0; i < numCourses; i++) {
            if (pre_count[i] == 0) {
                cur_ready.push_back(i);
            }
        }
        int remain = numCourses;
        vector<int> new_ready;
        while (remain > 0 && !cur_ready.empty()) {
            new_ready.clear();
            for (auto course : cur_ready) {
                for (auto i : graph[course]) {
                    if (--pre_count[i] == 0) {
                        new_ready.push_back(i);
                    }
                }
                --remain;
            }
            swap(cur_ready, new_ready);
        }
        return remain == 0;
    }
};
// @lc code=end

