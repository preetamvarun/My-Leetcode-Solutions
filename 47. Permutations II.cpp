class Solution {
public:
    void solve(vector<int>input, set<vector<int>> &ans, int idx, int n){
        if(idx == n - 1){
            ans.insert(input);
            return;
        }
        for(int i = 0; i < input.size(); i++){
            if(i >= idx){
                vector<int>in = input;
                swap(in[i],in[idx]);
                solve(in,ans,idx+1,n);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res; set<vector<int>>ans;
        solve(nums,ans,0,nums.size());
        for(auto it = ans.begin(); it != ans.end(); it++) res.push_back(*it);
        return res;
    }
};
