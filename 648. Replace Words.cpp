class Solution {
public:
    string checkRoot(string word, multimap<int,string>mp1){
        string res = "";
        for(auto it = mp1.begin(); it != mp1.end(); it++){
            if(it->first > word.size()) break;
            string s = it->second; bool b = true; int j = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != word[j]){
                    b = false;
                    break;
                }
                j++;
            }
            if(b){
                res = it->second;
                break;
            }
        }
        return res;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int>mp;
        for(int i = 0; i < dictionary.size(); i++){
            mp[dictionary[i]] = dictionary[i].size();
        }
        multimap<int,string>mp1;
        for(auto it = mp.begin(); it != mp.end(); it++){
            mp1.insert(pair<int,string>({it->second,it->first}));
        }
        string ans = "", str = "";
        vector<string>words;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] != ' '){
                str += sentence[i];
            }
            else{
                words.push_back(str);
                str = "";
            }
        }
        words.push_back(str);
        for(int i = 0; i < words.size(); i++){
            string st = checkRoot(words[i],mp1);
            if(st != "") words[i] = st;
        }
        for(int i = 0; i < words.size(); i++){
            ans += words[i];
            if(i != words.size()-1) ans += " ";
        }
        return ans;
    }
};
