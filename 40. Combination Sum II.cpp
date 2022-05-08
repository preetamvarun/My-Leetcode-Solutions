class Solution {
public:
    void f(vector<int>input,int target,vector<int>output,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(output);
            return;
        }
        for(int i = 0; i < input.size(); i++){
            if(i > 0 && input[i] == input[i-1]){
                continue;
            }
            else if(target - input[i] >= 0){
                if(i == 0 || input[i] != input[i-1]){
                    vector<int>in,out = output;
                    copy(input.begin()+(i+1),input.begin()+input.size(),back_inserter(in));
                    out.push_back(input[i]);
                    f(in,target-input[i],out,ans);
                } 
            }
            else if(target - input[i] < 0){
                /*
                since the array is sorted if target - input[i] < 0 then obviously all the elements which are on the right side of ith index 
                will result in -ve (target - input[i]) only. so we can break out from the for loop.
                */
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort the canditates vector so that all the combinations will be in sorted order
        sort(candidates.begin(),candidates.end());
        vector<int>output; vector<vector<int>>ans;
        f(candidates,target,output,ans);
        return ans;
    }
};
