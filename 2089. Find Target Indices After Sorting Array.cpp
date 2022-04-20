class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<int> ans;
        if(binary_search(nums.begin(),nums.end(), target)){
            int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
            if(up == lo){
                ans.push_back(lo);
            }else{
                for(int i = lo; i <= up; i++){
                    ans.push_back(i);
                }
            }
        }
    return ans;
    }
};
