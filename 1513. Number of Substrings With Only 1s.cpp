class Solution {
public:
    int numSub(string s) {
        long long int ans = 0, ones = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                ans += (ones*(ones+1))/2;
                ones = 0;
            }
        }
        ans += (ones * (ones + 1))/2;
        return ans % 1000000007;
    }
};