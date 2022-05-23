class Solution {
public:
    void solve(vector<vector<int>> &ans, int k, vector<int>output, vector<int>input){
        if(output.size() == k){
            ans.push_back(output);
            return;
        }
        else if(output.size() > k || input.size() == 0){
            return;
        }
        else if(input.size() + output.size() < k){
            return;
        }
        vector<int>op1 = output, op2 = output;
        op1.push_back(input[0]);
        input.erase(input.begin());
        solve(ans,k,op1,input);
        solve(ans,k,op2,input);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>input,output;
        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) input.push_back(i+1);
        solve(ans,k,output,input);
        return ans;
    }
};
