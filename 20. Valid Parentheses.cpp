class Solution {
    
public:
    bool isValid(string s) {
        stack<char>st;
        bool ans;
        
        for(int i = 0; i < s.size(); i++){
            
            if(st.size() == 0){
                st.push(s[i]);
            }
            
            else {
                
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
                
                else if( (st.top() == '(' && s[i] == ')') || (st.top() == '{'  && s[i] == '}') || 
                        (st.top() == '[' && s[i] == ']') ){
                    st.pop();
                }
                
                else{
                    st.push(s[i]);
                }
            }
        }
        
        st.size() == 0 ? ans = true : ans = false;
        
        return ans;
        
    }
};
