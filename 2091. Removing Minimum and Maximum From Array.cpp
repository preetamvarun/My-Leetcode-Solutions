class Solution {

public:

    int minimumDeletions(vector<int>& nums) {

        int n = nums.size(), max_num = INT_MIN, min_num = INT_MAX, ans = INT_MAX, min_pos = -1, max_pos = -1;

        if(n == 1) return 1;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] > max_num){

                max_num =  nums[i];

                max_pos = i+1;

            }

            if(nums[i] < min_num){

                min_num = nums[i];

                min_pos = i+1;

            }

        }

        ans = min(ans,max(max_pos,min_pos));

        ans = min(ans,max(n-max_pos+1,n-min_pos+1));

        ans = min(ans,max_pos+n-min_pos+1);

        ans = min(ans,n-max_pos+1+min_pos);

        return ans;

    }

};
