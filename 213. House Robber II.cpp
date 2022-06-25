class Solution {
public:
    int solve(int idx, vector<int> &nums, vector<int> &dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int fr = nums[idx] + solve(idx - 2, nums, dp);
        int sr = 0 + solve(idx - 1, nums, dp);
        return dp[idx] = max(fr,sr);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0],nums[1]);
        vector<int>IgnoreLastHouse, IgnoreFirstHouse;
        for(int i = 0; i < nums.size() - 1; i++) IgnoreLastHouse.push_back(nums[i]);
        for(int i = 1; i < nums.size(); i++) IgnoreFirstHouse.push_back(nums[i]);
        int n = IgnoreLastHouse.size();
        vector<int>dp1(n,-1),dp2(n,-1);
        return max(solve(n-1,IgnoreLastHouse,dp1),solve(n-1,IgnoreFirstHouse,dp2));
    }
};
