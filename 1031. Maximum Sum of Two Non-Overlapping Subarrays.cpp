class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<pair<int,pair<int,int>>>vec,vec2;
        int sum = 0, i = 0, j = 0, N = nums.size();
        while(j < N){
            sum += nums[j];
            if((j-i+1) == firstLen){
                vec.push_back({sum,{i,j}});
                sum -= nums[i];
                i++;
            }
            j++;
        }
        sum = 0, i = 0, j = 0;
        while(j < N){
            sum += nums[j];
            if((j-i+1) == secondLen){
                vec2.push_back({sum,{i,j}});
                sum -= nums[i];
                i++;
            }
            j++;
        }        
        // check for overlapping conditions and return the maximum answer
        int s1,s2,e1,e2, ans = 0, sum1 = 0, sum2 = 0;
        for(int i = 0; i < vec.size(); i++){
            for(int j = 0; j < vec2.size(); j++){
                if((vec[i].second.second < vec2[j].second.first) || 
                   (vec2[j].second.second < vec[i].second.first)){
                    ans = max(ans,vec[i].first+vec2[j].first);
                }
            }
            
        }
        
        return ans;
    }
};