/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 *
 * https://leetcode.com/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (37.70%)
 * Likes:    240
 * Dislikes: 1099
 * Total Accepted:    51.3K
 * Total Submissions: 136K
 * Testcase Example:  '[197,130,1]'
 *
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the
 * following rules:
 *
 * For 1-byte character, the first bit is a 0, followed by its unicode code.
 * For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
 * followed by n-1 bytes with most significant 2 bits being 10.
 *
 * This is how the UTF-8 encoding would work:
 *
 * ⁠  Char. number range  |        UTF-8 octet sequence
 * ⁠     (hexadecimal)    |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠  0000 0000-0000 007F | 0xxxxxxx
 * ⁠  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 * ⁠  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 *
 * Given an array of integers representing the data, return whether it is a
 * valid utf-8 encoding.
 *
 *
 * Note:
 * The input is an array of integers. Only the least significant 8 bits of each
 * integer is used to store the data. This means each integer represents only 1
 * byte of data.
 *
 *
 *
 * Example 1:
 *
 * data = [197, 130, 1], which represents the octet sequence: 11000101 10000010
 * 00000001.
 *
 * Return true.
 * It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte
 * character.
 *
 *
 *
 *
 * Example 2:
 *
 * data = [235, 140, 4], which represented the octet sequence: 11101011
 * 10001100 00000100.
 *
 * Return false.
 * The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes
 * character.
 * The next byte is a continuation byte which starts with 10 and that's
 * correct.
 * But the second continuation byte does not start with 10, so it is invalid.
 *
 *
 */

// @lc code=start
class Solution {
public:
    const int b4 = 0b11110;
    const int b3 = 0b1110;
    const int b2 = 0b110;
    const int b1 = 0;
    bool isFollowing(int num)
    {
        return num >> 6 == 0b10;
    }
    int remain(int num)
    {
        if ((num >> 3) == b4)
        {
            return 3;
        }
        if ((num >> 4) == b3)
        {
            return 2;
        }
        if (num >> 5 == b2)
        {
            return 1;
        }
        if (num >> 7 == 0)
        {
            return 0;
        }
        return -1;
    }
    bool validUtf8(vector<int> &data)
    {
        for (size_t i = 0; i < data.size();)
        {
            int r = remain(data[i]);
            if (r < 0) {
                return false;
            }
            ++i;
            if (r && i >= data.size())
            {
                return false;
            }
            for (; r && i < data.size(); r--, i++)
            {
                if (!isFollowing(data[i]))
                {
                    return false;
                }
            }
            if (r)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// XXX: 255这种情况没处理好