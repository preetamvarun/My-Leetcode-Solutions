class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       map<int,int>m; vector<int>ans;
        
        for(int  i = 0; i < nums.size(); i++){
            
            if(m.size() == 0){
                m[nums[i]] = i;
            }
            
            else{
                
                if(m.find(target - nums[i]) == m.end()){
                    m[nums[i]] = i;
                }
                
                else{
                    ans.push_back(i);
                    ans.push_back(m[target-nums[i]]);
                    break;
                }
                
            }
            
        }
        
        return ans;
    }
};
