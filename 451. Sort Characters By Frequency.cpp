class Solution {
public:
    
    static bool cmp(pair<int,int>p1,pair<int,int>p2){
        return p1.second > p2.second;
    }
    
    string frequencySort(string s) {
        
       map<char,int>mp; string ans = "";
        
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        
        vector<pair<char,int>>vec;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            vec.push_back({it->first,it->second});
        }
        
        sort(vec.begin(),vec.end(),cmp);
        
       for(int i = 0; i < vec.size(); i++){
            for(int y = 0; y < vec[i].second; y++){
                ans += vec[i].first;
            }
        }
        
        
        return ans;
    }
};
