class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        while(mp.find(original) != mp.end())original = original * 2;
        return original;
    }
};
