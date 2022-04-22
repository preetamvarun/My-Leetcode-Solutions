class Solution {
public:
    int startIndex = -1;
    
    bool isSubstring(string s, string part,int part_len){
        int i = 0, j = 0, start = 0;
        int length = s.size();
        while(i < length){
            if(s[i] == part[j]){
                j++;
                i++;
                if(j == part_len){
                    startIndex = start;
                    return true;
                }
            }
            else{
                start++;
                i = start;
                j = 0;
            }
        }
        return false;
    }
    
    string removeOccurrences(string s, string part) {
        int i = 0, j = 0, len = part.size();
        while(isSubstring(s,part,len)){
            s.erase(startIndex,len);
        }
        return s;
    }
};
