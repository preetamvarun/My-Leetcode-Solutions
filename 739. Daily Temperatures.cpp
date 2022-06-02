class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        int n = temperatures.size();
        vector<int>ans(n);
        for(int i = 0; i < n; i++) ans[i] = -1;
        for(int i = n-1; i >= 0; i--){
            if(i == n - 1){
                st.push({temperatures[i],i});
                ans[i] = 0;
            }
            else{
                while(temperatures[i] >= st.top().first){
                    st.pop();
                    if(st.size() == 0){
                        st.push({temperatures[i],i});
                        ans[i] = 0;
                        break;
                    }
                }
                if(st.size()){
                    ans[i] = st.top().second - i;
                    st.push({temperatures[i],i});   
                }
            }
        }
        return ans;
    }
};
