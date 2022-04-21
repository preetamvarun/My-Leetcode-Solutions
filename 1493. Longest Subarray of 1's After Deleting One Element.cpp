class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0, ans = 0; 
        vector<int>vec;
        
        // if array contains only one's then remove a single one from it
        
        bool isAllOnes = true;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                isAllOnes = false;
                break;
            }
        }
        
        if(isAllOnes){
            return nums.size()-1;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
            } else{
                if(count != 0){
                    vec.push_back(count);
                    count = 0;
                }
                vec.push_back(0);
            }
        }
        if(count != 0){
            vec.push_back(count);
        }
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] == 0 && (i > 0 && i < vec.size()-1)){
                if(vec[i-1] != 0 && vec[i+1] != 0){
                    ans = max(ans,(vec[i-1] + vec[i+1]));
                }
            }
            else{
                ans = max(ans,vec[i]);
            }
        }
        return ans;
    }
};
