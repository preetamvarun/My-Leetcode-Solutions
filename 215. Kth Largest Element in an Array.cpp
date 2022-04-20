class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int ans;
        
       for(int i = 0; i <nums.size(); i++){
           if(i == k-1){
               ans = nums[i];
               break;
           }
       }
        return ans;
    }
};
