/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int c1[26] = {0}, c2[26] = {0};
        for (size_t i = 0; i < s.size(); i++) {
            c1[s[i]-'a'] ++;
            c2[t[i]-'a'] ++;
        }
        return memcmp(c1, c2, sizeof(c1)) == 0;
    }
};
