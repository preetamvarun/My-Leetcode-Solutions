class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,pair<int,int>>mp;
        int ref_val = -1;
        for(int i = 0; i < cards.size(); i++){
            if(mp.find(cards[i]) == mp.end()){
                mp[cards[i]] = {i,-1};
            }
            else{
                if(mp[cards[i]].second == -1){
                    mp[cards[i]].second = i;
                }
                else{
                    pair<int,int> newPair = {mp[cards[i]].second,i};
                    if(ref_val == -1){
                        ref_val =  mp[cards[i]].second - mp[cards[i]].first + 1;
                    }
                    else{
                        ref_val = min(ref_val,mp[cards[i]].second - mp[cards[i]].first + 1);
                    }
                    mp[cards[i]] = newPair;
                }
            }
        }
        int ans = INT_MAX;
        if(mp.size() == cards.size()) return -1;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second.second != -1){
                ans = min(ans,it->second.second-it->second.first+1);
            }
        }
        if(ref_val != -1) ans = min(ans,ref_val);
        return ans;
    }
};
