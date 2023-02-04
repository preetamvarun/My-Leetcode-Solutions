class Solution {
public:
    void solve(vector<int>nums, int i, int n, int max_or, map<int,int,greater<int>> &mp){
        if(i == n){
            mp[max_or]++;
            return;
        }
        solve(nums,i + 1,n,max_or|nums[i],mp);
        solve(nums,i + 1,n,max_or,mp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int,greater<int>>mp;
        solve(nums, 0, nums.size(), 0, mp);
        return mp.begin()->second;
    }
};
