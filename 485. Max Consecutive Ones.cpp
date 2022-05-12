class Solution {

public:

    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ans = 0, c = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 1) c++;

            else{

                ans = max(ans,c);

                c = 0;

            }

        }

        return max(ans,c);

    }

};
