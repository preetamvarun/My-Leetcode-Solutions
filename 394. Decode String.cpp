class Solution {
public:
    string decodeString(string s) {
        string ans = "", subans = "", str = "";
        stack<string>st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                st.push("[");
            }
            else if(isdigit(s[i])){
                str += s[i];
                if(isdigit(s[i+1]) == false){
                    st.push(str);
                    str = "";
                }
            }
            else if(s[i] == ']'){
                while(st.top() != "["){
                    subans += st.top();
                    st.pop();
                }
                st.pop();
                int k = stoi(st.top());
                st.pop();
                for(int i = 0; i < k; i++){
                    ans += subans;
                }
                st.push(ans);
                subans = "";
                ans = "";
            }
            else{
                string x = "";
                x += s[i];
                st.push(x);
            }
        }
        // reverse(ans.begin(),ans.end());
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
