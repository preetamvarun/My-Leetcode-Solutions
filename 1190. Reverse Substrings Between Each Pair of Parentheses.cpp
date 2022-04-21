class Solution {
public:
    string reverseParentheses(string s) {
        
        string ans = ""; 
        
        map<int,pair<int,int>,greater<int>>mp;
        
        int ob = 1, c = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                mp[ob] = {i,-1};
                ob++;
            }
            else if(s[i] == ')'){
                for(auto it = mp.begin(); it != mp.end(); it++){
                    if(it->second.second == -1){
                        it->second.second = i;
                        break;
                    }
                }
            }
        }
        
        multimap<int,pair<int,int>>anotherMap;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            anotherMap.insert(pair<int,pair<int,int>>((it->second.second - it->second.first),{it->second.first,it->second.second}));
        }
        
        for(auto it = anotherMap.begin(); it != anotherMap.end(); it++){
            if(it->first > 2){
                string temp = "";
                for(int i = it->second.first+1; i <= it->second.second-1; i++){
                    temp += s[i];
                }
                reverse(temp.begin(),temp.end());
                for(int i = it->second.first+1; i <= it->second.second-1; i++){
                    s[i] = temp[c];
                    c++;
                }
                c = 0;
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '(' && s[i] != ')'){
                ans += s[i];
            }
        }
        
        return ans;
    }
};
