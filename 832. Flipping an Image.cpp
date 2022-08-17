class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            vector<int>row = image[i];
            reverse(row.begin(),row.end());
            for(int i = 0; i < row.size(); i++){
                row[i] = row[i] == 0 ? 1 : 0;
            }
            image[i] = row;
        }
        return image;
    }
};
