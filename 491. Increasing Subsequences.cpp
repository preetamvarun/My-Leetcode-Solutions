class Solution {
public:
    void solve(vector<int>input,vector<int>output,set<vector<int>> &ans){
        if(input.size() == 0){
            if(output.size() >= 2) ans.insert(output);
            return;
        }
        if(output.size() >= 2) ans.insert(output);
        for(int i = 0; i < input.size(); i++){
            if(((output.size() == 0 && i != 0) || (output.size() == 0 && i == 0))
              ||((output.size() != 0 && i == 0 && input[i] >= output[output.size()-1])) 
              || ((output.size() != 0 && i != 0 && input[i] >= output[output.size()-1]))){
                vector<int>in,out = output;
                copy(input.begin()+(i+1),input.begin()+input.size(),back_inserter(in));
                out.push_back(input[i]);
                solve(in,out,ans);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans; vector<int>output = {};
        solve(nums,output,ans); vector<vector<int>>result;
        for(auto it = ans.begin(); it != ans.end(); it++) result.push_back(*it);
        return result;
    }
};
