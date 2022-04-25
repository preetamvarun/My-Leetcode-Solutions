class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int a = piles.size() - 1, b = 0, m = a - 1, ans = 0;
        while(m - b >= 1){
            ans += piles[m];
            a -= 2;
            m -= 2;
            b++;
        }
        return ans;
    }
};
