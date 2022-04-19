class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int k = s1.size(); map<char,int>mp;
        
        for(int i = 0; i < s1.size(); i++) mp[s1[i]]++;
        
        int count = mp.size(); bool ans = false;
        
        int i = 0, j = 0, len = s2.size();
        
        while(j < len){
            
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){
                    count--;
                }
            }
            
            if(j - i + 1 == k){
                
                if(count == 0){
                    ans = true;
                    break;
                }
                
                if(mp.find(s2[i]) != mp.end()){
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        count++;
                    }
                }
                
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};