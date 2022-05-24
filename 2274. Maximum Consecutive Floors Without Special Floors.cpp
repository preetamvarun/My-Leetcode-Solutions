class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans = 0, bs = 0;
        int val = max(abs(bottom-special[0]), abs(top-special[special.size()-1]));
        for(int i = 0; i < special.size()-1; i++){
            if(special[i+1] - special[i] > 1){
                ans = special[i+1]-(special[i]+1);
                bs = max(ans,bs);
            }
        }
        return max(max(ans,bs),val);
    }
};
