class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i] * 2) != mp.end()){
                if(arr[i] != 0) return true;
                else{
                    if(mp[arr[i]] > 1) return true;
                }
            }
        }
        return false;
    }
};
