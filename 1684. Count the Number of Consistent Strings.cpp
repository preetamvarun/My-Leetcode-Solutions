class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        for(int i = 0; i < allowed.size(); i++){
            mp[allowed[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            string str = words[i]; bool b = true;
            for(int i = 0; i < str.size(); i++){
                if(mp.find(str[i]) == mp.end()){
                    b = false;
                    break;
                }
            }
            if(b){
                ans++;
            }
        }
        return ans;
    }
};
