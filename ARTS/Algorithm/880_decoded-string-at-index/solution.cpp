class Solution {
public:
    string decodeAtIndex(string S, int K) {
        if (K == 1) {
            return string(1, S[0]);
        }
        // XXX: 类型不够大，用的int
        vector<int64_t> len;
        len.reserve(S.length());
        len.push_back(1);
        for (size_t i = 1; i < S.length() && len.back() < K; i++) {
            if(isalpha(S[i])) {
                len.push_back(len.back()+1);
            } else {
                len.push_back(len.back()*(S[i]-'0'));
            }
        }
        // i will never be zero
        for (size_t i = len.size()-1; i >= 0; i--) {
            if(isdigit(S[i])) {
                K = K % len[i-1];
                if (K  == 0) {
                    K = len[i-1];
                }
            }
            if (K == len[i]  && isalpha(S[i])) {
                return string(1, S[i]);
            }
        }
        // XXX: 最后没有返回，以为c++不会报错
        // cannot go here
        return S;
    }
};
