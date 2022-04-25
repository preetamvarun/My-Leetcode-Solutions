class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans; 
        for(int i = 0; i < l.size(); i++){
            int left_range = l[i];
            int right_range = r[i];
            vector<int>vec;
            int sum = 0, n = right_range - left_range + 1;
            if(n <= 1){
                ans.push_back(true);
            }
            else{
                for(int i = left_range; i <= right_range; i++){
                    vec.push_back(nums[i]);
                }
                bool flag = true;
                sort(vec.begin(),vec.end());
                for(int i = 1; i < vec.size() - 1; i++){
                    if((vec[i] - vec[i-1]) != (vec[i+1] - vec[i])){
                        flag = false;
                        break;
                    }
                }
                flag ? ans.push_back(true) : ans.push_back(false);
            }
        }
        return ans;
    }
};
