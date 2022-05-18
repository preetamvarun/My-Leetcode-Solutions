class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>winners,loosers;
        // calculate loosers
        for(int i = 0; i < matches.size(); i++){
            int l = matches[i][1];
            loosers[l]++;
        }
        // calculate winners 
        for(int i = 0; i < matches.size(); i++){
            int w = matches[i][0];
            if(loosers.find(w) == loosers.end()){
                winners[w]++;
            }
        }
        vector<vector<int>>ans;vector<int>v1,v2;
        for(auto it = winners.begin(); it != winners.end(); it++){
            v1.push_back(it->first);
        }
        ans.push_back(v1);
        for(auto it = loosers.begin(); it != loosers.end(); it++){
            if(it->second == 1){
                v2.push_back(it->first);
            }
        }
        ans.push_back(v2);
        return ans;
    }
};
