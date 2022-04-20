class Solution {
public:
    bool isPalindrome(string s) {
        
        string a = "", b = ""; bool ans;
        
        for(int i= 0; i < s.size(); i++){
            if(isalnum(s[i])){
                a += tolower(s[i]);
            }
        }
        
        b = a;
        reverse(a.begin(), a.end());
        
        a == b ? ans = true : ans = false;
        
        
        return ans;
    }
};
