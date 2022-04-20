class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, j = 0, sum = 0, avg, ans = 0;
        
        while(j < arr.size()){
            sum += arr[j];
            
            if(j-i+1 == k){
                avg = sum / k;
                if(avg >= threshold){
                    ans++;
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};