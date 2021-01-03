/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (46.01%)
 * Likes:    339
 * Dislikes: 896
 * Total Accepted:    100.2K
 * Total Submissions: 217.8K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 *
 *
 *
 * 'A' : Absent.
 * 'L' : Late.
 * ⁠'P' : Present.
 *
 *
 *
 *
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 *
 * Example 1:
 *
 * Input: "PPALLP"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "PPALLL"
 * Output: False
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        char p = '\0';
        int na = 0;
        int ncl = 0;
        for (auto c : s) {
            if (c == 'A') {
                if (++na  > 1) {
                    return false;
                }
            } else if (c == 'L') {
                if (p == 'L') {
                    if (++ncl > 2) {
                        return false;
                    }
                } else {
                    ncl = 1;
                }
            }
            p = c;
        }
        return true;
    }
};
// @lc code=end

