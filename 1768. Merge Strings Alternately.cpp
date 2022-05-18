class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        if(word1.size() == word2.size()){
            for(int i = 0; i < word1.size(); i++){
                ans += word1[i];
                ans += word2[i];
            }
        }
        else if(word1.size() > word2.size()){
            int j = 0;
            while(j < word2.size()){
                ans += word1[j];
                ans += word2[j];
                j++;
            }
            for(int i = j; i < word1.size(); i++){
                ans += word1[i];
            }
        }
        else if(word2.size() > word1.size()){
            int j = 0;
            while(j < word1.size()){
                ans += word1[j];
                ans += word2[j];
                j++;
            }
            for(int i = j; i < word2.size(); i++){
                ans += word2[i];
            }
        }
        return ans;
    }
};
