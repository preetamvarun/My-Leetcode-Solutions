class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i= 0, j = 0, N = nums.size(), ans = 0, sum = 0;
        map<int,int>mp;
        while(j < N){
            mp[nums[j]]++;
            sum += nums[j];
            while(mp[nums[j]] > 1){
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            if(mp[nums[j]] == 1){
                ans = max(ans,sum);
            }
            j++;
        }
        return ans;
    }
};
