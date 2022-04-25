class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int>res,vec_que,ans;
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            map<char,int>mp;
            for(int i = 0; i < str.size(); i++){
                mp[str[i]]++;
            }
            res.push_back(mp.begin()->second);
        }
        
        sort(res.begin(),res.end());
        for(int i = 0; i < queries.size(); i++){
            string str = queries[i];
            map<char,int>mp;
            for(int i = 0; i < str.size(); i++){
                mp[str[i]]++;
            }
            vec_que.push_back(mp.begin()->second);
        }
        
        for(int i = 0; i < vec_que.size(); i++){
            int x =  upper_bound(res.begin(),res.end(),vec_que[i]) - res.begin();
            ans.push_back(res.size() - x);
        }
        return ans;
    }
};
