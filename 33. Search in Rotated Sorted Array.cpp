class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size() - 1, mid, ans = -1;
        
        while(start <= end){
            
            mid = (start + end) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            else if(end - start <= 1){
                if(nums[start] == target){
                    ans = start;
                }
                else if(nums[end] == target){
                    ans = end;
                }
                return ans;
            }
            
            // check if first half is sorted and target lies in that range 
            else if(nums[start] < nums[mid]){
                if(nums[start] <= target && nums[mid] >= target){
                    end = mid;
                }
                else{
                    start = mid + 1;
                }
            }
            
            // check if second half is sorted and target lies in that range
            else if(nums[mid] < nums[end]){
                if(nums[mid] <= target && nums[end] >= target){
                    start = mid;
                }
                else{
                    end = mid - 1;
                }
            }
            
        }
        

        return ans;
    }
};
