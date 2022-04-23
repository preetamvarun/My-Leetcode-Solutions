class Solution {
public:
    vector<vector<string>>vec;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(int i = 0; i < strs.size(); i++){
            string x = strs[i];
            sort(x.begin(),x.end());
            mp[x].push_back(strs[i]);
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            vec.push_back(it->second);
        }
        
        return vec;
    }
};
