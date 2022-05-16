class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = -1, j = nums.size()-1, i = 0;
        sort(nums.begin(),nums.end());
        while(i < j){
            ans = max(ans,(nums[i] + nums[j]));
            i++;
            j--;
        }
        return ans;
    }
};
