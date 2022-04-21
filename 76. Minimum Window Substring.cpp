class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        map<char,int>mp;
        int i = 0, j = 0, count = 0, len = s.size(), ans = INT_MAX;
        int start_index = -1, end_index = -1;
        string ans_string = "";
        for(int i = 0; i < t.size(); i++) mp[t[i]]++;
        count = mp.size();
        while(j < len){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
                if(count == 0){
                    if(j-i+1 < ans){
                        start_index = i;
                        end_index = j;
                        ans = end_index - start_index + 1;
                    }
                }
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                        }
                        else if(mp[s[i]] <= 0){
                            if(j - (i+1) + 1 < ans){
                                start_index = i+1;
                                end_index = j;
                                ans = end_index - start_index + 1;
                            }
                        }
                    }                    
                    else{
                        if(j - (i+1) + 1 < ans){
                            start_index = i + 1;
                            end_index = j;
                            ans = end_index - start_index + 1;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(start_index == -1 || end_index == -1){
            return "";
        }
        for(int i = start_index; i <= end_index; i++){
            ans_string += s[i];
        }
        return ans_string;
    }
};
