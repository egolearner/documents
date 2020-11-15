class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            if (nums.size()  <= 2) {
                return true;
            }
            bool changed = false;
            for (int i = 0; i < nums.size()-2; i++) {
                int& first = nums[i];
                int& second = nums[i+1];
                int& third = nums[i+2];
                if (first  <= second  &&  second  <= third) {
                    continue;
                }
                if (changed) {
                    return false;
                }
                if (first > second  &&  second > third) {
                    return false;
                }
                changed = true;
                if (first <= second  &&  second > third) {
                    if (first<third) {
                        second = third;
                    } else {
                        third = second;
                    }
                }
                if (second  <= third  &&  first > second) {
                    first = second;
                }
            }
            return true;
        }
};

