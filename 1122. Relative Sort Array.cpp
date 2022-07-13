class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>ans,temp;
        for(int i = 0; i < arr1.size(); i++) mp[arr1[i]]++;
        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < mp[arr2[i]]; j++){
                ans.push_back(arr2[i]);
            }
        }
        sort(arr2.begin(),arr2.end());
        for(int i = 0; i < arr1.size(); i++){
            if(binary_search(arr2.begin(),arr2.end(),arr1[i]) == false){
                temp.push_back(arr1[i]);
            }
        }
        sort(temp.begin(),temp.end());
        for(int i = 0; i < temp.size(); i++) ans.push_back(temp[i]);
        return ans;
    }
};
