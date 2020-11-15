class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);
        if (candies.empty()) {
            return result;
        }
        // XXX 忘了*
        int max_c = *std::max_element(candies.begin(), candies.end());
        for (size_t i = 0; i < candies.size(); i++) {
            if (candies[i]+extraCandies >= max_c) {
                result[i] = true;
            }
        }
        return result;
    }
};
