class Solution {
public:
    void f(vector<int>input,int n, vector<vector<int>> &ans, int index){
        
        if(index+1 == n){
            ans.push_back(input);
            return;
        }
        
        for (int i = 0; i < input.size(); i++){
            if(i >= index){
                vector<int>in = input;
                swap(in[i],in[index]);
                f(in,n,ans,index+1);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>>ans;
        f(nums,len,ans,0);
        return ans;
    }
};
