class Solution {
public:
    int numberOfSubstrings(string s) {
        int cur_index_a = -1, cur_index_b = -1, cur_index_c = -1;
        int ans = 0, min_index;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                cur_index_a = i;
            } 
            else if(s[i] == 'b'){
                cur_index_b = i;
            } 
            else{
                cur_index_c = i;
            }
            if(cur_index_a != -1 && cur_index_b != -1 && cur_index_c != -1){
                min_index = min(cur_index_a,cur_index_b);
                min_index = min(min_index, cur_index_c);
                ans = ans + (min_index + 1);
            }
        }
        return ans;
    }
};