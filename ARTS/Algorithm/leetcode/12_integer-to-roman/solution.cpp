class Solution {
public:
    string intToRoman(int num) {
        char ones[] = "IXCM";
        char fives[] = "VLD";
        int index = 0;
        string result;
        while (num) {
            int cur = num % 10;
            if (cur == 4) {
                result.push_back(fives[index]);
                result.push_back(ones[index]);
            } else if (cur == 9) {
                // XXX 顺序反了
                result.push_back(ones[index+1]);
                result.push_back(ones[index]);
            } else {
                int singles = cur % 5;
                if(singles > 0) {
                    result.insert(result.end(), singles, ones[index]);
                }
                if (cur >= 5) {
                    result.push_back(fives[index]);
                }
            }
            // XXX %= 
            num /= 10;
            index++;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// XXX 题解中用贪心的思路
