class Solution {
public:
    bool rotateString(string s, string goal) {
        string rotate_str = s;
        rotate_str.push_back(rotate_str[0]);
        rotate_str.erase(rotate_str.begin());
        while(rotate_str != s){
            rotate_str.push_back(rotate_str[0]);
            rotate_str.erase(rotate_str.begin());
            if(rotate_str == goal){
                return true;
            }
        }
        return false;
    }
};
