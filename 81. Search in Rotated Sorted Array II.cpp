class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        // Firstly, remove duplicate values
        
        while(start < end && nums[start] == nums[start + 1]){
            start++;
        }
        
        while(start < end && nums[end] == nums[end - 1]){
            end--;
        }
        
        while(start <= end){
            mid = (start + end) / 2;
            
            if(nums[mid] == target){
                return true;
            }
            
            else if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid;
                }
                else{
                    start = mid + 1;
                }
            }
            
            else if(nums[mid] <= nums[end]){
                if(nums[mid] <= target && target <= nums[end] ){
                    start = mid;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
