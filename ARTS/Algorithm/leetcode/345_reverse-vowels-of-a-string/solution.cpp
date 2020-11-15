class Solution {
public:
    inline bool isVowel(char c) {
        char l = tolower(c);
        switch (l) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        vector<char> vowel;
        vector<int> index;
        vowel.reserve(s.size());
        index.reserve(s.size());
        for (size_t i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowel.push_back(s[i]);
                index.push_back(i);
            }
        }
        for (size_t i = 0, j = index.size()-1; i < index.size(); i++, j--) {
            // XXX 写成s[i]
            s[index[i]]  = vowel[j];
        }
        return s;
    }
};

// 用头尾指针思路更加高效
