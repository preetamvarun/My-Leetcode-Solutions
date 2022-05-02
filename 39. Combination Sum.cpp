class Solution {
public:
    void f(vector<int>input, vector<int>output, int target, vector<vector<int>> &ans){
        if(input.size() == 0){
            if(target == 0) ans.push_back(output);
            return;
        }
        if(target-input[0] >= 0){
            vector<int>op1 = output;
            op1.push_back(input[0]);
            f(input,op1,target-input[0],ans);
            input.erase(input.begin()+0);
            f(input,output,target,ans);
        }
        else{
            input.erase(input.begin() + 0);
            f(input,output,target,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans; vector<int>res;
        f(candidates,res,target,ans);
        return ans;
    }
};
