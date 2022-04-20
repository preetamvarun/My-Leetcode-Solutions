class Solution {
public:
    int countHomogenous(string s) {
        long long int count = 1, ans = 0;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == s[i+1]){
                count++;
            }
            else{
                ans += (count * (count + 1))/2;
                count = 1;
            }
        }
        ans += (count * (count + 1))/2;
        return ans % 1000000007;
    }
};