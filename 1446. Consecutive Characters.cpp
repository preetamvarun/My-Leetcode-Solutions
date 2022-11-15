class Solution {
public:
    int maxPower(string s) {
        int count = 1, ans = 1;
        bool same_character = true;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] != s[i+1]){
                same_character = false;
                break;
            }
        }
        if(same_character) return s.size();
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i+1]){
                count++;
            }
            else{
                ans = max(ans,count);
                count = 1;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};
