class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0, i = 0, j = 0, len = word.size();
        map<char,int,greater<char>>mp;
        while(j < len){
            if(word[j] == 'a'){
                if(mp.size() <= 1 && mp.begin()->first <= word[j]){
                    mp[word[j]]++;
                } else{
                    mp.clear();
                    i = j;
                    mp[word[j]]++;
                }
            }
            else if(word[j] == 'e' ){
                if(mp.size() <= 2 && mp.begin()->first <= word[j]){
                    mp[word[j]]++;
                }
                else{
                    mp.clear();
                    i = j;
                    mp[word[j]]++;
                }
            }
            else if(word[j] == 'i'){
                if(mp.size() <= 3 && mp.begin()->first <= word[j]){
                    mp[word[j]]++;
                }
                else{
                    mp.clear();
                    i = j;
                   mp[word[j]]++;
                }
            }
            else if(word[j] == 'o'){
                if(mp.size() <= 4 && mp.begin()->first <= word[j]){
                    mp[word[j]]++;
                }
                else{
                    mp.clear();
                    i = j;
                    mp[word[j]]++;
                }
            }
            else if(word[j] == 'u'){
                if(mp.size() <= 5 && mp.begin()->first <= word[j]){
                    mp[word[j]]++;
                    if(mp.size() == 5)ans = max(ans,j-i+1);
                }
                else{
                    mp.clear();
                    i = j;
                    mp[word[j]]++;
                }
            }
            j++;
        }
        return ans;
    }
};
