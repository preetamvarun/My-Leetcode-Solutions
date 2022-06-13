class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        int ans;
        int c = 1; int target = nums.size()/2;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1]){
                c++;
                if(c > target){
                    ans = nums[i];
                    break;
                }
            }
            else{
                c = 1;
            }
        }
        return ans;
    }
};
