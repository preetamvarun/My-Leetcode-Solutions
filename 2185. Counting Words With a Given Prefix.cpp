class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            string s = words[i]; int j = 0, len = 0;
            for(int t = 0; t < s.size(); t++){
                if(s[t] == pref[j]){
                    len++;
                    if(len == pref.size()){
                        ans++;
                        break;
                    }
                }
                else{
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};
