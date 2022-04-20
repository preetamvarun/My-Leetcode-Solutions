class Solution {
public:
    
    vector<vector<int>>ans; map<vector<int>,int>mp;
    
    void solve(vector<int>input,vector<int>output){
        
        if(input.size() == 0){
            
            sort(output.begin(),output.end());
            
            if(mp.find(output) == mp.end()){
                mp[output] = 1;
                ans.push_back(output);
            }
            
            return;
        }
        
        vector<int>op1 = output;
        vector<int>op2 = output;
        
        op2.push_back(input[0]);
        input.erase(input.begin());
        
        solve(input,op1);
        solve(input,op2);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>output = {};
        solve(nums,output);
        return ans;
    }
};
