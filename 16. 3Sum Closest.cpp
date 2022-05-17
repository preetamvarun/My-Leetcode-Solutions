class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX, res, diff;
        for(int i = 0; i < nums.size()-2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int lo = i + 1, hi = nums.size()-1, sum = target - nums[i];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum) return target;
                    else if(nums[lo] + nums[hi] < sum){
                        diff = sum - nums[lo] - nums[hi];
                        if(diff < ans){
                            ans = diff;
                            res = nums[lo] + nums[hi] + nums[i];
                        }
                        lo++;
                    }
                    else{
                        diff = nums[lo] + nums[hi] - sum;
                        if(diff < ans){
                            ans = diff;
                            res = nums[lo] + nums[hi] + nums[i];
                        }
                        hi--;
                    }
                }
            }
        }
        return res;
    }
};
