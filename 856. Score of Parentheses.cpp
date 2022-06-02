class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string>st;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push("(");
            else if(st.top() == "(" && s[i] == ')'){
                st.pop();
                st.push("1");
            }
            else st.push(")");
        }
        string inter = "";
        while(st.size()){
            inter += st.top();
            st.pop();
        }
        reverse(inter.begin(),inter.end());
        for(int i = 0; i < inter.size(); i++){
            if(inter[i] == '(') st.push("(");
            else if(inter[i] == ')'){
                int v = stoi(st.top()) * 2;
                st.pop();
                st.pop();
                if(st.size() > 0 && (st.top() != ")" && st.top() != "(")){
                    v += stoi(st.top());
                    st.pop();
                }
                st.push(to_string(v));
            }
            else if(inter[i] != ')' && inter[i] != '('){
                if(st.size() > 0 && (st.top() != ")" && st.top() != "(")){
                    int v = stoi(st.top()) + 1;
                    st.pop();
                    st.push(to_string(v));   
                }
                else{
                    string x = "";
                    x += inter[i];
                    st.push(x);
                }
            }
        }
        return stoi(st.top());
    }
};
