class Solution {
public:
    string reverseWords(string s) {
        vector<string>v; string ans = "", res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                ans += s[i];
            }
            else{
                v.push_back(ans);
                ans = "";
            }
        }
        v.push_back(ans);
        for(int i = 0; i < v.size(); i++){
            reverse(v[i].begin(),v[i].end());
            res += v[i];
            if(i != v.size()-1) res += " ";
        }
        return res;
    }
};
