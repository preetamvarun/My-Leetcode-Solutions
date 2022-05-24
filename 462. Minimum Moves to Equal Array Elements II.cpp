class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, mid;
        sort(nums.begin(),nums.end());
        mid = nums.size()/2;
        for(int i = 0; i < mid; i++) ans += nums[mid]-nums[i];
        for(int i = nums.size()-1; i > mid; i--) ans += nums[i]-nums[mid];
        return ans;
    }
};
