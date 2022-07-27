class Solution {
public:
    int lengthOfLastWord(string s) {
       string str = "";
        vector<string>words;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(str.size() != 0){
                    words.push_back(str);
                }
                str = "";
            }
            else{
                str += s[i];
            }
        }
        if(str.size() != 0) words.push_back(str);
        return words[words.size()-1].size();
    }
};
