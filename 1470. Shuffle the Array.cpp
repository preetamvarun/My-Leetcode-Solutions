class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int x = n, j = x;
        for(int i = 0; i <= x-1; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            j++;
        }
        return ans;
    }
};
