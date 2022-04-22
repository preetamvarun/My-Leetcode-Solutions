class Solution {
public:
    bool rotateString(string s, string goal) {
        string rs = s;
        rs.push_back(rs[0]);
        rs.erase(rs.begin());
        while(rs != s){
            rs.push_back(rs[0]);
            rs.erase(rs.begin());
            if(rs == goal){
                return true;
            }
        }
        return false;
    }
};
