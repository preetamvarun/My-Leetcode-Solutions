class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int N = s.size();
        char res[N];
        for(int i = 0; i < N; i++){
            res[i] = '#';
        }
        int i = 0;
        for(int y = 0; y < indices.size(); y++){
            res[indices[y]] = s[i];
            i++;
        }
        string ans = "";
        for(int i = 0; i < N; i++){
            ans += res[i];
        }
        return ans;
    }
};
