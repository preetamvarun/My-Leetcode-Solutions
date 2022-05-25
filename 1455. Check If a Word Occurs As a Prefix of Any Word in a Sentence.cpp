class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>words; string str = "";
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] != ' '){
                str += sentence[i];
            }
            else{
                words.push_back(str);
                str = "";
            }
        }
        words.push_back(str);
        int ans = 0; string strs = "";
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            if(s.size() >= searchWord.size()){
                int len = 0, j = 0;
                for(int t = 0; t < s.size(); t++){
                    if(s[t] == searchWord[j]){
                        len++;
                        if(len == searchWord.size()){
                            return i + 1;
                        }
                    }
                    else{
                        break;
                    }
                    j++;
                }
            }
        }
        return -1;
    }
};
