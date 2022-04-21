class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0, j = 1;
        
        if(s.size() < 3){
            return 0;
        }
        
        while(j < s.size() - 1){
            
            if(s[j-1] != s[j] && s[j] != s[j+1] && s[j-1] != s[j+1]){
                ans++;
            }
            
            j++;   
        }
    
        return ans;
    }
};
