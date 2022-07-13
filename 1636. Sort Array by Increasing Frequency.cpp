class Solution {
public:
    static bool comp(pair<int,int>a, pair<int,int>b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return b.second > a.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        vector<pair<int,int>>vec;
        for(auto it = mp.begin(); it != mp.end(); it++){
            vec.push_back({it->first,it->second});
        }
        sort(vec.begin(),vec.end(),comp);
        vector<int>ans;
        for(auto it = vec.begin(); it != vec.end(); it++){
            int x = it->second;
            for(int i = 0; i < x; i++) ans.push_back(it->first);
        }
        return ans;
    }
};
