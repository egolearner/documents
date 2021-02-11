class Solution {
public:
    string largestMerge(string word1, string word2)
    {
        string res;
        res.reserve(word1.length() + word2.length());
        auto p1 = word1.c_str();
        auto p2 = word2.c_str();
        while (*p1 && *p2) {
            if (*p1 < *p2) {
                res.append(p2, 1);
                ++p2;
            } else if (*p1 > *p2) {
                res.append(p1, 1);
                ++p1;
            } else {
                auto pp1 = p1 + 1;
                auto pp2 = p2 + 1;
                for (; *pp1 == *pp2 && *pp1; ++pp1, ++pp2) {
                }
                if (*pp1 > *pp2) {
                    res.append(p1, 1);
                    ++p1;
                } else {
                    res.append(p2, 1);
                    ++p2;
                }
            }
        }
        if (*p1) {
            res.append(p1);
        } else if (*p2) {
            res.append(p2);
        }
        return res;
    }
};
//XXX 用"1和"2保存，再读取的时候会自动变。对vim的register不够熟悉。
