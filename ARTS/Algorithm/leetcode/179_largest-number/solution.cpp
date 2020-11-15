/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (29.93%)
 * Likes:    2528
 * Dislikes: 276
 * Total Accepted:    220.9K
 * Total Submissions: 736.1K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number.
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1]
 * Output: "1"
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [10]
 * Output: "10"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<long> times(nums.size());
        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0);
        for (size_t i = 0; i < nums.size(); i++) {
            for (int j = 10; true; j *=10 ) {
                if (j > nums[i]) {
                    times[i] = j;
                    break;
                }
            }
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            long f = times[b] * nums[a] + nums[b];
            long s = times[a] * nums[b] + nums[a];
            return f > s;
        });
        if (nums[indices[0]] == 0) {
            return "0";
        }
        string res;
        for (auto i : indices) {
            res += to_string(nums[i]);
        }
        return res;
    }
};
// @lc code=end

/* XXX 想用一个不concat字符串做比较的实现，结果不如concat快
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> str;
        for(auto i:nums) str.push_back(to_string(i));
        sort(str.begin(),str.end(),[](string a,string b){
           return a+b>b+a;
        });
        string res;
        for(auto s:str)res=res+s;
        if(res.at(0)=='0'){
            return "0";
        }
        return res;
    }
};

XXX 使用字符串做比较但不concat，报Runtime Error
Line 12: Char 21: runtime error: load of null pointer of type 'const char' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:21:21

[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.reserve(nums.size());
        for(auto i : nums) {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            bool ac = false, bc = false;
            for (const char* aa = a.c_str(), *bb = b.c_str(); true; ) {
                if (*aa < *bb) {
                    return false;
                } else if (*aa > *bb) {
                    return true;
                } else {
                    ++aa;
                    ++bb;
                    if (*aa == '\0') {
                        if (ac) {
                            break;
                        }
                        aa = b.c_str();
                        ac = true;
                    }
                    if (*bb == '\0') {
                        if (bc) {
                            break;
                        }
                        bb = a.c_str();
                        bc = true;
                    }
                }
            }
            return true;
        });
        if (strs[0][0] == '0') {
            return "0";
        }
        string res;
        for (auto& s : strs) {
            res += s;
        }
        return res;
    }
};
*/

