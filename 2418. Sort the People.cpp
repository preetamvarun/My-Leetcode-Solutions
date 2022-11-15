class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>>mp;
        for(int i = 0; i < names.size(); i++){
            mp[heights[i]] = names[i];
        }
        vector<string>ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
