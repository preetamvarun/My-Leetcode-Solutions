class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, res = 0, N = nums.size();
        for(int i = 0; i < nums.size(); i++){
            res += nums[i];
        }
        for(int i = 0; i <= N; i++){
            ans += i;
        }
        return abs(res - ans);
    }
};
