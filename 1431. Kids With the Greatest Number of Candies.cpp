class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_cand = 0;
        vector<bool>ans;
        for(int i = 0; i < candies.size(); i++){
            max_cand = max(max_cand, candies[i]);
        }
        for(int i = 0; i < candies.size(); i++){
            ans.push_back(candies[i] + extraCandies >= max_cand);
        }
        return ans;
    }
};
