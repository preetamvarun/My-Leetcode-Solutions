class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
        +,+,+
        -,+,+
        -,-,+
        */
        vector<int> v = nums;
        sort(nums.begin(),nums.end(), greater<int>());
        int ans = nums[0] * nums[1] * nums[2];
        sort(v.begin(),v.end());
        ans = max(ans, (nums[0] * nums[1] * nums[nums.size()-1]));
        ans = max(ans, (nums[0] * nums[nums.size()-1] * nums[nums.size()-2]));
        return ans;
    }
};
