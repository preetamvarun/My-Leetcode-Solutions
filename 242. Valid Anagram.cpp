class Solution {
public:
    bool isAnagram(string s, string t) {
        
        bool ans;
        
        map<char,int>mp; int count, len = s.size(), k = t.size();
        
        if(t.size() != s.size()){
            return false;
        }
        
        for(int i = 0; i < len; i++){
            mp[s[i]]++;
        }
        
        count = mp.size();
        
        for(int i = 0; i < k; i++){
            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--;
                if(mp[t[i]] == 0){
                    count--;
                }
            }
        }
        
        count == 0 ? ans = true : ans = false;
        
        return ans;
        
    }
};
