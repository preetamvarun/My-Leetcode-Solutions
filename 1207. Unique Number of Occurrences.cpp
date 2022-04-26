class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i = 0; i < arr.size(); i++)mp[arr[i]]++;
        vector<int>v;
        for(auto it = mp.begin();it != mp.end();it++)v.push_back(it->second);
        sort(v.begin(),v.end());
        for(int i = 0; i<v.size()-1;i++){
            if(v[i] == v[i+1]) return false;
        }
        return true;
    }
};
