class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp; string ans = "";
        bool fop = false; string str = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                fop = true;
            }
            else if(fop && s[i] != ')'){
                str += s[i];
            }
            if(s[i] == ')'){
                mp[str] = "?";
                fop = false;
                str = "";
            }
        }
        for(int i = 0; i < knowledge.size(); i++){
            if(mp[knowledge[i][0]] == "?"){
                mp[knowledge[i][0]] = knowledge[i][1];
            }
        }
        fop = false; str = ""; 
        for(int i = 0; i < s.size(); i++){
            if(fop == false && s[i] != '('){
                ans += s[i];
            }
            if(s[i] == '('){
                fop = true;
            }
            else if(fop && s[i] != ')'){
                str += s[i];
            }
            if(s[i] == ')'){
                ans += mp[str];
                fop = false;
                str = "";
            }
        }
        return ans;
    }
};
