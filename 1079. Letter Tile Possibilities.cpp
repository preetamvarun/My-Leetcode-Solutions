class Solution {
public:
    int cal_num_fact(int num){
        long x1 = 1;
        for(int i = 1; i <= num; i++) x1 = x1 * i;
        return x1;
    }
    int cal_denom_fact(int num){
        long y1 = 1;
        for(int i = 1; i <= num; i++) y1 = y1 * i;
        return y1;
    }
    int cal_ans(string str){
        map<char,int>mp;
        for(int i = 0; i < str.size(); i++) mp[str[i]]++;
        long ans1 = cal_num_fact(str.size()), ans2 = 1;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans2 *= cal_denom_fact(it->second);
        }
        return mp.size() ? ans1/ans2 : 0;
    }
    void solve(string input,string output,set<string>&s){
        if(input.size() == 0){
            s.insert(output);
            return;
        }
        string op1 = output;
        op1 += input[0];
        input.erase(input.begin());
        solve(input,output,s);
        solve(input,op1,s);
    }
    int numTilePossibilities(string tiles) {
        int ans = 0;
        set<string>s;
        sort(tiles.begin(),tiles.end());
        solve(tiles,"",s);
        for(auto it = s.begin(); it != s.end(); it++){
            ans += cal_ans(*it);
        }
        return ans;
    }
};
