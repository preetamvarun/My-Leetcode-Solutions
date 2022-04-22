class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        int up = 0; vector<bool>ans;
        
        for(int i = 0; i < pattern.size(); i++) if(isupper(pattern[i])) up++;
        
        for(int i = 0; i < queries.size(); i++){
            
            string s = queries[i]; int upper = 0, x = 0; bool flag = true;
            
            for(int i = 0; i < s.size(); i++) if(isupper(s[i])) upper++;
            
            if(up == upper){
                for(int i = 0; i < s.size(); i++){
                    if(s[i] == pattern[x]){
                        x++;
                        if(x == pattern.size()) break;
                    }
                    else{
                        if( (isupper(s[i]) && islower(pattern[x])) || (isupper(s[i]) && isupper(pattern[x]))){
                            flag = false;
                            ans.push_back(false);
                            break; 
                        }
                    }
                }
                
                if(flag) ans.push_back(true);
            }
            else ans.push_back(false);
        }
        
        return ans;
    }
};
