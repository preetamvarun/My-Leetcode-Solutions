class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // Don't always think forwards
        int goalPost = nums.size() - 1;
        
        // for every iteration check to see whether there is a chance to shrink the 
        // goal post 
        
        
        /*
            [2,3,1,1,4]
            Instead of iterating from the forwards do it from backwards.
            Intiailly the goalPost (destination) will be at index 4
            start iterating from index 3. See if you can reach index 4 from index 3
            if you can do so, then set the goalPost to index 3. because any way you
            will be going to index 4 if you can reach index 3. Then again check if you 
            can reach index 3 from index 2. If you can reach index 3 from index 2 then 
            set the goalPost to index 2 because any way you are going to reach index 3 if you arrive at index2. Repeat this process.
            
        */
        
        if(nums.size() == 1){
            return true;
        }
        
        
        
        for(int i = nums.size() - 2; i >= 0; i--){
            if(i + nums[i] >= goalPost){
                goalPost = i;
            }
        }
        
        return goalPost == 0;
    }
};
