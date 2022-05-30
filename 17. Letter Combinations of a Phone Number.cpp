class Solution {
public:
    void solve(vector<string>input,string output,vector<string> &ans){
        if(input.size() == 0){
            ans.push_back(output);
            return;
        }
        string str = input[0];
        input.erase(input.begin());
        for(int i = 0; i < str.size(); i++){
            string op = output;
            op = op + str[i];
            solve(input,op,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string>ans, input;
        map<char,string>mp;
        mp['2'] = "abc"; mp['3'] = "def"; mp['4'] = "ghi";
        mp['5'] = "jkl"; mp['6'] = "mno"; mp['7'] = "pqrs";
        mp['8'] = "tuv"; mp['9'] = "wxyz";
        for(int i = 0; i < digits.size(); i++) input.push_back(mp[digits[i]]);
        solve(input,"",ans);
        return ans;
    }
};
