class Solution {
public:
    static bool cmp(pair<int,int>p1, pair<int,int>p2){
        return p1.second < p2.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int ans = 0;
        map<int,int>mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it = mp.begin(); it != mp.end(); it++){
            v.push_back({it->first,it->second});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i < v.size(); i++){
            if(k == 0){
                break;
            }
            if(k >= v[i].second){
                k -= v[i].second;
                v[i].second = 0;
            }
            else if(k < v[i].second){
                v[i].second -= k;
                break;
            }
        }
        for(int i = 0; i < v.size(); i++){
            if(v[i].second != 0){
                ans++;
            }
        }
        return ans;
    }
};
