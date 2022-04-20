class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, N = s.size(), ans = 0;
        while(j < N){
            maxCost -= abs(s[j] - t[j]);
            while(maxCost < 0){
                maxCost += abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};