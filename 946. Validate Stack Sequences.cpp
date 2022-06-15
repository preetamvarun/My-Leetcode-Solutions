class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st; int j = 0;
        for(int i = 0; i < pushed.size(); i++){
            while(st.size()){
                if(st.top() == popped[j]){
                    st.pop();
                    j++;
                }
                else{
                    break;
                }
            }
            st.push(pushed[i]);
        }
        while(st.size()){
            if(st.top() == popped[j]){
                st.pop();
                j++;
            }
            else{
                break;
            }
        }
        return st.size() == 0;
    }
};
