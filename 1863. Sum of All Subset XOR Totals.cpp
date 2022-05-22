// leetcode problem number :  1863

class Solution {
public:
    void solve(int &ans, vector<int>input, vector<int>ds){
        if(input.size() == 0){
            int cnt = 0;
            for(int i = 0; i < ds.size(); i++){
                cnt ^= ds[i];
            }
            ans += cnt;
            return;
        }
        vector<int>ds2 = ds;
        ds2.push_back(input[0]);
        input.erase(input.begin());
        solve(ans,input,ds);
        solve(ans,input,ds2);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0; vector<int>ds = {};
        solve(ans,nums,ds);
        return ans;
    }
};
