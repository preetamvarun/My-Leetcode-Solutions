class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        int num = INT_MIN, ans = INT_MAX;
        for(auto it = mp.begin(); it != mp.end(); it++) num = max(num,it->second);
        map<int,pair<int,int>>anotherMap;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == num){
                if(anotherMap.find(nums[i]) == anotherMap.end()){
                    anotherMap[nums[i]].first = i;
                    anotherMap[nums[i]].second = i;
                }
                else anotherMap[nums[i]].second = i;
            }
        }
        for(auto it = anotherMap.begin(); it != anotherMap.end(); it++){
            ans = min(ans,(abs(it->second.second-it->second.first)));
        }
        return ans + 1;
    }
};
