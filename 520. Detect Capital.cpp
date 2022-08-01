class Solution {
public:
    bool checkUpper(string s){
        for(int i = 0; i < s.size(); i++){
            if(islower(s[i])) return false;
        }
        return true;
    }
    bool checkLower(string s){
        for(int i = 0; i < s.size(); i++){
            if(isupper(s[i])) return false;
        }
        return true;
    }
    bool checkUL(string s){
        bool a = true, b = true;
        if(islower(s[0])) a = false;
        for(int i = 1; i < s.size(); i++){
            if(isupper(s[i])){
                b = false;
                break;
            }
        }
        return a && b;
    }
    bool detectCapitalUse(string word) {
        if(checkUpper(word)) return true;
        if(checkLower(word)) return true;
        if(checkUL(word)) return true;
        return false;
    }
};
