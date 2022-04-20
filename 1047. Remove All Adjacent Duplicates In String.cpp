class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st; string ans = "";
        
        for(int i = 0; i < s.size(); i++){
            if(st.size() == 0){
                st.push(s[i]);
            }
            else{
                st.top() == s[i] ? st.pop() : st.push(s[i]);
            }
        }
        
        while(st.size() != 0){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
