class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        for(int i = 0; i < numbers.size(); i++){
            int x = target - numbers[i];
            if(binary_search(numbers.begin(), numbers.end(), x)){
                int lo = lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();
ans.push_back(i+1);
                ans.push_back(lo+1);
                if(ans[0] == ans[1]){
                    int up = upper_bound(numbers.begin(),numbers.end(),x) - numbers.begin();
                    ans[1] = up;
                }
                break;
            }
        }
        return ans;
    }
};
