class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       
        vector<int>ans;
        
        int i = 0, j = 0, k = p.size(), len = s.size(), count;
        
        map<char,int>mp;
        
        for(int i = 0; i < k; i++){
            mp[p[i]]++;
        }
        
        count = mp.size();
        
        while(j < len){
            
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count--;
                }
            }
            
            if(j - i + 1 == k){
                
                if(count == 0){
                    ans.push_back(i);
                }
                
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
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
