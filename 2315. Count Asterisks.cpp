class Solution {
public:
    int countAsterisks(string s) {
        int bar_count = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '|'){
                bar_count++;
            }
            if(bar_count == 2){
                bar_count = 0;
            }
            if(s[i] == '*' && bar_count == 0){
                ans++;
            }
            
        }
        return ans;
    }
};
