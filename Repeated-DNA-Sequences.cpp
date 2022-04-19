class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      map<string,int>mp,mp1;
      int j = 0; string res = "";
      vector<string>ans;
      while(j < s.size()){
          res += s[j];
          if(res.size() == 10){
              if(mp.find(res) == mp.end()){
                  mp[res]++;
              }
              else{
                  mp1[res]++;
              }
              res.erase(res.begin()+0);
          }
          j++;
      }
        for(auto it = mp1.begin(); it != mp1.end(); it++){
            ans.push_back(it->first);
        }
        return ans;
    }
};