class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0, i = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zeros++;
        }
        while(zeros > 0){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                zeros--;
            }
            else{
                i++;
            }
        }
    }
};
