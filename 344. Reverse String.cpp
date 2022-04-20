class Solution {
public:
    
    void reverse(vector<char> &s){
        if(s.size() == 0){
            return;
        }
        
        int k = s[0];
        
        s.erase(s.begin());
        reverse(s);
        s.push_back(k);
    }
    
    void reverseString(vector<char>& s) {
        
        reverse(s);
        
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << " ";
        }
        
    };
};
