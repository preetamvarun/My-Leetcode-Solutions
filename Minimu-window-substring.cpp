class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, len = s.size(), count = 0, ans = 0;
        map<char,int>mp;
        while(j < len){
            mp[s[j]]++;
            count++;
            if(mp[s[j]] == 1){
                ans = max(ans,count);
            }
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
                count--;
            }
            j++;
        }
        return ans;
    }
};