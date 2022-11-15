class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        // [1,1,2,2,2,3,3,4,5,6,6,7,7]
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        vector<int>answerPair;
        int pairCount = 0, independentCount = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > 1){
                pairCount = pairCount + (it->second/2);
                if(it->second % 2 != 0){
                    independentCount++;
                }
            }
            else if(it->second == 1) independentCount++;
        }
        answerPair.push_back(pairCount);
        answerPair.push_back(independentCount);
        return answerPair;
    }
};
