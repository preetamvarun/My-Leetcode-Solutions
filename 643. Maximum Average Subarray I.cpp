class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = -10001;
        int len = nums.size(), i = 0, j = 0, sum = 0;
        while(j < len){
            sum += nums[j];
            if(j - i + 1 == k){
                double x = (double)sum/k;
                avg = max(avg,x);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return avg;
    }
};