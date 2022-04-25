class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v; long long int sum = 0;
        int i = 0, j = 0, N = nums.size();
        while(i < N){
            sum += nums[j];
            v.push_back(sum);
            if(j == N - 1){
                sum = 0;
                i++;
                j = i;
            }
            else{
                j++;
            }
        }
        sort(v.begin(),v.end());
        for(int i = left - 1; i < right; i++){
            sum += v[i];
        }
        return sum % 1000000007;
    }
};
