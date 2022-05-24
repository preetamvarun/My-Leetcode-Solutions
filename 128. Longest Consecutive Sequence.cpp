class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        else if(nums.size() == 1) return 1;
        int ans = 0, best_ans = 0;
        vector<int>num;
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        for(auto it = mp.begin(); it != mp.end(); it++) num.push_back(it->first);
        for(int i = 0; i < num.size()-1; i++){
            if(num[i]-num[i+1] == -1){
                ans++;
            }
            else{
                best_ans = max(ans,best_ans);
                ans = 0;
            }
        }
        return max(ans,best_ans) + 1;
    }
};
