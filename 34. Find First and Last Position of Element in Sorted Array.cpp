class Solution {
    
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n = nums.size();
        int mid = n/2;
        
        if(n == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        if(target <= nums[mid]){
            for(int i = 0; i < mid; i++){
                if(nums[i] == target){
                    if(ans.size() <= 1) ans.push_back(i);
                    if(ans.size() == 2){
                        ans[ans.size() - 1] = i;
                    }
                }
            }
        }
        
        if(target >= nums[mid]){
            for(int i = mid; i < nums.size(); i++){
                if(nums[i] == target){
                    if(ans.size() <= 1) ans.push_back(i);
                    if(ans.size() == 2){
                        ans[ans.size() - 1] = i;
                    }
                }
            }
        }
        
        if(ans.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        if(ans.size() == 1){
            ans.push_back(ans[0]);
        }
        
        return ans;
    }
};
