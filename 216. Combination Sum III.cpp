class Solution {
public:
    void solve(vector<int>input, vector<int>output, vector<vector<int>> &ans, int k, int sum){
        if(output.size() == k){
            if(sum == 0){
                ans.push_back(output);
            }
            return;
        }
        else if(output.size() > k || sum < 0){
            return;
        }
        for(int i = 0; i < input.size(); i++){
            if(sum - input[i] >= 0){
                vector<int>in, out = output;
                copy(input.begin()+(i+1), input.begin()+input.size(), back_inserter(in));
                out.push_back(input[i]);
                solve(in,out,ans,k,sum-input[i]);   
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>input = {1,2,3,4,5,6,7,8,9}, output;
        vector<vector<int>>ans;
        solve(input,output,ans,k,n);
        return ans;
    }
};
