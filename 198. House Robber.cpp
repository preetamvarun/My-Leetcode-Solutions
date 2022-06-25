class Solution {
public:
    int solve(int idx, vector<int> &houses, vector<int> &dp){
        if(idx < 0) return 0;
        if(idx == 0) return houses[idx];
        if(dp[idx] != -1) return dp[idx];
        int fr = houses[idx] + solve(idx - 2,houses,dp);
        int sr = 0 + solve(idx-1,houses,dp);
        return dp[idx] = max(fr,sr);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n,-1);
        // return solve(n-1,nums,dp);
        // vector<int>dp(n,0);
        // dp[0] = nums[0];
        // for(int i = 1; i < n; i++){
        //     int fr = i - 2 >= 0 ? nums[i] + dp[i-2] : nums[i];
        //     int sr = 0 + dp[i-1];
        //     dp[i] = max(fr,sr);
        // }
        // return dp[n-1];
        int prev1 = nums[0], prev2, curri;
        for(int i = 1; i < n; i++){
            int fr = i - 2 >= 0 ? nums[i] + prev2 : nums[i];
            int sr = 0 + prev1;
            curri = max(fr,sr);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};
