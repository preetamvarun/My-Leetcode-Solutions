class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // [10,7,6,1,-1,-7]
        map<int,int>mp;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = 1;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(-nums[i]) != mp.end()){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
