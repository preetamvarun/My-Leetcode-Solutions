class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int mul = 1, len = nums.size(), i = 0, j = 0, ans = 0;
        
        if(k <= 1){
            return 0;
        }
        
        while(j < len){
            
            mul *= nums[j];
            
            if(mul >= k){
                
                while(mul >= k){
                    mul /= nums[i];
                    i++;
                }
                                 
            }
            
            ans += (j - i + 1);
            
            j++;
        }
        
                
        return ans;
    }
};