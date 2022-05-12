class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, r = 0, l = 0;
        for(int i = 0; i < s.size(); i++){
            s[i] == 'L' ? l++ : r++;
            if(l == r){
                l = 0;
                r = 0;
                ans++;
            }
        }
        return ans;
    }
};
