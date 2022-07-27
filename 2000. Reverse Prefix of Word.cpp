class Solution {
public:
    string reversePrefix(string word, char ch) {
        int fO = -1;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                fO = i;
                break;
            }
        }
        if(fO == -1) return word;
        string ans = "";
        for(int i = fO; i >= 0; i--){
            ans += word[i];
        }
        for(int j = fO + 1; j < word.size(); j++){
            ans += word[j];
        }
        return ans;
    }
};
