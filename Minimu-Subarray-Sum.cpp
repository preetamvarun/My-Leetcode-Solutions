class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0, ans = INT_MAX, i = 0, j = 0, len = nums.size();
        
        
        while(j < len){
            sum += nums[j];
            if(sum >= target){
                while(sum >= target){
                    sum -= nums[i];
                    ans = min(ans,j-i+1);
                    i++;
                }
            }
            j++;
        }
        
        if(ans == INT_MAX){
            ans = 0;
        }
        
        return ans;
    }
};