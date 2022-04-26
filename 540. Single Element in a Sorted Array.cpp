class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int mid, start = 0, end = nums.size() - 1, ans;
        
        if(nums.size() == 1) return nums[0];
        
        while(start <= end){
            
            mid = end - (end-start)/2;
            
            if(end - start + 1 == 3){
                ans = (nums[start] == nums[mid] && nums[mid] != nums[end]) ? 
                nums[end] : ans = nums[start];
                break;
            }
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                ans = nums[mid];
                break;
            }
            
            // If rem is 1 go in the same direction
            // If rem is 3 go in the opposite direction
            (end - start + 1) % 4 == 1 ?  
                nums[mid] == nums[mid+1] ? start = mid : end = mid 
                : 
                nums[mid] == nums[mid-1] ? start = mid + 1 : end = mid - 1;
        }
        
        return ans;
    }
};
