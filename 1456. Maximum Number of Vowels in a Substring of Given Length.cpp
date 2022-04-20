class Solution {
public:
    int maxVowels(string s, int k) {
        int j = 0, len = s.size(), ans = 0, count = 0, i =0;
        map<char,int>mp;
        while(j < s.size()){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                mp[s[j]]++;
                count++;
            }
            if(j - i + 1 == k){
                ans = max(ans,count);
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]--;
                    count--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};