class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int,int>mp; bool ans = false;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                if(i - mp[nums[i]] <= k){
                    ans = true;
                    break;
                }
                else{
                    mp[nums[i]] = i;
                }
            }
        }
        
        return ans;
    }
};