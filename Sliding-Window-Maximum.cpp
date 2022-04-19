class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        map<int,int,greater<int>>mp; vector<int>ans;
        
        int i = 0, j = 0, len = nums.size();
        
        while(j < len){
            mp[nums[j]]++;
            if(j - i + 1 == k){
                ans.push_back(mp.begin()->first);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                 mp.erase(nums[i]);   
                }
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};