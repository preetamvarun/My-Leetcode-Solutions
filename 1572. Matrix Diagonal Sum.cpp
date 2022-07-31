class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        /*
            [10,20,30,40
             50,60,70,80
             11,22,33,44
             12,23,34,45]
        */
        /*
            [1,2,3
             4,5,6
             7,8,9]
        */
        int n = mat.size(), ans = 0, cnt = 0;
        
        // calculate the primary diagnol
        
        for(int i = 0; i < n; i++){
            vector<int>in = mat[i];
            ans += in[cnt];
            cnt++;
        }
        
        // calculate the secondary diagnol
        cnt--;
        if(n % 2 != 0){
            for(int i = 0; i < n; i++){
                vector<int>in = mat[i];
                if(cnt != (n-1)/2) ans += in[cnt];
                cnt--;
            }
        }
        else{
            for(int i = 0; i < n; i++){
                vector<int>in = mat[i];
                ans += in[cnt];
                cnt--;
            }
        }
        
        return ans;
    }
};
