class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool ans; int n = s1.size();
        for(int i = 0; i < n; i++){
            if(s1[i] >= s2[i]){
                ans = true;
                continue;
            }
            else{
                ans = false;
                break;
            }
        }
        if(ans == true) return ans;
        for(int i = 0; i < n; i++){
            if(s2[i] >= s1[i]){
                ans = true;
                continue;
            }
            else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};
