class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, N = nums.size(), c1 = k, ans = 0, count = 0;
        
        while(j < N){
            if(nums[j] != 1){
                c1--;
                while(c1 < 0){
                    if(nums[i] == 0) c1++;
                    count--;
                    i++;
                } 
            } 
            count++;
            ans = max(ans,count);
            j++;
        }
        return ans;
        
    }
};