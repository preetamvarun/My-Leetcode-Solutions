class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        int rows = matrix.size(), columns = matrix[0].size();
        for(int i = 0; i < columns; i++){
            vector<int>v;
            for(int y = 0; y < rows; y++){
                v.push_back(matrix[y][i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
