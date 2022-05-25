class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1,mp2;
        for(int i = 0; i < nums1.size(); i++){
            mp1[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++){
            mp2[nums2[i]] = 1;
        }
        vector<int>v1,v2;
        for(auto it = mp1.begin(); it != mp1.end(); it++){
            if(mp2.find(it->first) == mp2.end()){
                v1.push_back(it->first);
            }
        }
        for(auto it = mp2.begin(); it != mp2.end(); it++){
            if(mp1.find(it->first) == mp1.end()){
                v2.push_back(it->first);
            }
        }
        vector<vector<int>>ans;
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
