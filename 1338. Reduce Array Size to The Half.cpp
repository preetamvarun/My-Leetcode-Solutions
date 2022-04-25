class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<int>vec;
        for(auto it = mp.begin(); it != mp.end(); it++){
            vec.push_back(it->second);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        int half = arr.size() / 2;
        int count = 0, j = 0;
        while(count < half){
            count += vec[j];
            j++;
        }
        return j;
    }
};
