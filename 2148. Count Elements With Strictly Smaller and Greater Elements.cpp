class Solution {
public:
    int countElements(vector<int>& nums) {        
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        
        /*
            -3 : 1
             3 : 2
             90 : 1
        */
        
        /*
            0 : 1
        */
        
        int ans = 0;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it != mp.begin()) ans += it->second;
        }
        
        auto it = mp.rbegin();
        
        if(ans > 0) ans -= it->second;
        
        return ans;
    }
};
