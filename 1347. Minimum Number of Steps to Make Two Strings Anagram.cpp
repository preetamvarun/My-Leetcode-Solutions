class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp1,mp2;
        for(int i = 0; i < s.size(); i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        int ans = 0;
        // traverse mp2
        for(auto it = mp2.begin(); it!= mp2.end(); it++){
            if(mp1.find(it->first) == mp1.end()){
                ans += it->second;
            }else{
                if(it->second > mp1[it->first]){
                    ans += it->second - mp1[it->first];
                }
            }
        }
        return ans;
    }
};
