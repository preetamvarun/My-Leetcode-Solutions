class Solution {
public:
    bool isVowel(char x){
        x = tolower(x);
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int i = 0, j = s.size()-1, c1 = 0, c2 = 0;
        while(i < j){
            if(isVowel(s[i])) c1++;
            if(isVowel(s[j])) c2++;
            i++;
            j--;
        }
        return c1 == c2;
    }
};
