class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool ans = false;
        
        for(int i = 1; i < arr.size() - 1; i++){
            if(arr[i]%2 != 0){
                if(arr[i-1]%2 != 0 && arr[i+1]%2 != 0){
                    ans = true;
                    break;
                }
            }
        }
        
        return ans;
    }
};
