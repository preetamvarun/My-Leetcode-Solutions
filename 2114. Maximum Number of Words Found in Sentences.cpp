class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int ans = 0;
        
        for(int i = 0; i < sentences.size(); i++){
            string s = sentences[i]; int count = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == ' '){
                    count++;
                }
            }
            
            ans = max(ans,count);
        }
        
        return ans + 1;
    }
};
