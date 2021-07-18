/*
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

0 <= s.length <= 3000
s consists of digits only.
*/
class Solution {
public:
    void restore(vector<string>&res, string&s, size_t ind, string& cur, size_t parts) {
        if (ind == s.size()) {
            if (parts == 4) {
                res.push_back(cur);
            }
            return;
        }
        if (parts == 4) {
            return;
        }
        size_t remain = s.size() - ind;
        if (remain < 4-parts || remain > (4-parts)*3) {
            return;
        }
        size_t cur_size = cur.size();
        if (parts > 0) {
            cur.push_back('.');
        }
        if (s[ind] == '0') {
            cur.push_back('0');
            restore(res, s, ind+1, cur, parts+1);
            cur.resize(cur_size);
            return;
        }
        int value = 0;
        while(ind < s.size()) {
            value = value * 10 + s[ind]-'0';
            if (value < 256) {
                cur.push_back(s[ind]);   
                ind++;
                restore(res, s, ind, cur, parts+1);    
            } else {
                break;
            }
        }
        cur.resize(cur_size);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur;
        restore(res, s, 0, cur, 0);
        return res;
    }
};
