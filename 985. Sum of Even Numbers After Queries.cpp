class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int bsum = 0; vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0) bsum += nums[i];
        }
        for(int i = 0; i < queries.size(); i++){
            int val = nums[queries[i][1]] + queries[i][0];
            if(nums[queries[i][1]] % 2 == 0) bsum -= nums[queries[i][1]];
            nums[queries[i][1]] = val;
            if(nums[queries[i][1]] % 2 == 0) bsum += nums[queries[i][1]];
            ans.push_back(bsum);
        }
        return ans;
    }
};
