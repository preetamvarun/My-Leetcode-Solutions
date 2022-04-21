class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int>mp;
        string ans;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = 1;
        }
        for(int i = 0; i < nums.size(); i++){
            string test = nums[i];
            for(int i = 0; i < test.size(); i++){
                test[i] = test[i] == '0' ? '1' : '0';
                if(mp.find(test) == mp.end()){
                    ans = test;
                    break;
                }
            }
        }
        return ans;
    }
};
