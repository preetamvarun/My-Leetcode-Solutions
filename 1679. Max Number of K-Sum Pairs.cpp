class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i < nums.size()/2; i++){
            if(mp[nums[i]] > 0 && nums[i] != k-nums[i]){
                if(mp.find(k-nums[i]) != mp.end()){
                    mp[nums[i]]--;
                    mp[k-nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    if(mp[k-nums[i]] == 0) mp.erase(k-nums[i]);
                    ans++;
                }   
            }
            else if(mp[nums[i]] > 0 && nums[i] == k-nums[i]){
                if(mp[nums[i]] >= 2){
                    mp[nums[i]] -= 2;
                    ans++;
                }
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
            }
        }
        return ans;
    }
};
