class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp; string ans = "";
        for(int i = 0; i < s.size(); i++) mp[s[i]]++;
        for(int i = 0; i < order.size(); i++){
            if(mp.find(order[i]) != mp.end()){
                for(int y = 0; y < mp[order[i]]; y++){
                    ans += order[i];
                }
                mp[order[i]] = 0;
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            for(int i = 0; i < it->second; i++){
                ans += it->first;
            }
        }
        return ans;
    }
};
