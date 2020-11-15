#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.empty()) {
            return false;
        }
        dp.resize(stones.size());
        stones_ = &stones;
        //XXX 缺少前面的判断
        return stones[1] == 1  &&  canCross(1, 1);
    }
    bool canCross(int curIndex, int step) {
        if (curIndex == stones_->size()-1) {
            return true;
        }
        for (int i = step-1; i <= step+1; i++) {
            if (i  ==  0) {
                continue;
            }
            auto iit = lower_bound(stones_->begin()+curIndex+1, stones_->end(), i+(*stones_)[curIndex]);
            if (iit != stones_->end()  &&  *iit -(*stones_)[curIndex]  == i) {
                //XXX 一开始，int j = *iit;，后来distance参数顺序反了
                int j = distance(stones_->begin(), iit);
                auto it = dp[j].find(i);
                if (it != dp[j].end()) {
                    if (it->second) {
                        dp[curIndex][step] = true;
                        return true;
                    } else {
                        continue;
                    }
                } else {
                    bool succ = canCross(j, i);
                    if (succ) {
                        dp[curIndex][step] = true;
                        return true;
                    }
                }
            }
        }
        dp[curIndex][step] = false;
        return false;
    }
private:
    std::vector<unordered_map<int, bool >> dp;
    vector<int>* stones_;
};
// 查看题解后，每次步长最多+1，里面的map也可以改为vector
