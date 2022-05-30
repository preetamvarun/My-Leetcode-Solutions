class Solution {
public:
    void solve(vector<string>input, set<string> &ans,string output){
        if(input.size() == 0){
            return;
        }
        string op1 = output, str = input[0];
        map<char,int>mp;
        for(int i = 0; i < str.size(); i++) mp[str[i]] = 1;
        bool b = true;
        for(int i = 0; i < op1.size(); i++){
            if(mp.find(op1[i]) != mp.end()){
                b = false;
                break;
            }
        }
        if(b)op1 += str;
        input.erase(input.begin());
        if(b) ans.insert(op1);
        ans.insert(output);
        if(b) solve(input,ans,op1);
        solve(input,ans,output);
    }
    int maxLength(vector<string>& arr) {
        set<string>ans;
        solve(arr,ans,"");
        int result = 0;
        for(auto it = ans.begin(); it != ans.end(); it++) cout << *it << " ";
        for(auto it = ans.begin(); it != ans.end(); it++){
            string s = *it;
            map<char,int>mp; bool b = true;
            for(int i = 0; i < s.size(); i++){
                mp[s[i]]++;
                if(mp[s[i]] > 1){
                    b = false;
                    break;
                }
            }
            if(b){
                int n = s.size();
                result = max(result,n);
            }
        }
        return result;
    }
};
