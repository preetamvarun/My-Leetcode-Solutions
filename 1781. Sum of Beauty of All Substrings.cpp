class Solution {
public:
    int beautySum(string s) {
        int sum = 0, i = 0, j = 0;
        int N = s.size(), _max = 0, _min = INT_MAX;
        map<char,int>mp;
        while(i < N){
            mp[s[j]]++;
            if(mp.size() > 1){
                _max = 0; _min = INT_MAX;
                for(auto it = mp.begin(); it != mp.end(); it++){
                    _max = max(_max,it->second);
                }
                for(auto it = mp.begin(); it != mp.end(); it++){
                    _min = min(_min,it->second);
                }
                sum += (_max - _min);
            }
            if(j == N-1){
                mp.clear();
                i++;
                j = i;
                _max = 0;
                _min = INT_MAX;
            }
            else{
                j++;
            }
        }
        return sum;
    }
};
