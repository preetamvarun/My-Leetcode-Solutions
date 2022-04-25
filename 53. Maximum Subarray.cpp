class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        bool all_neg = true;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                all_neg = false;
                break;
            }
        }
        
        // Maximum sub array sum :- Kadanes Algorithm
        
        int current_sum = 0, maximum_sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            current_sum += nums[i];
            if(current_sum < 0){
                current_sum = 0;
            }
            if(current_sum > maximum_sum){
                maximum_sum = current_sum;
            }
        }
        
        if(all_neg){
            int ans = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                ans = max(ans,nums[i]);
            }
            return ans;
        }
        
        return maximum_sum;
        
    }
};
