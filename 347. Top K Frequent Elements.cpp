class Solution {

public:

    

    static bool cmp(pair<int,int>p1,pair<int,int>p2){

        return p1.second > p2.second;

    }

    

    vector<int> topKFrequent(vector<int>& nums, int k) {

        

        vector<int>ans; map<int,int>mp; int count = 0;

        

        for(int i = 0; i < nums.size(); i++){

            mp[nums[i]]++;

        }

        

        vector<pair<int,int>>vec;

        

        for(auto it = mp.begin(); it!= mp.end(); it++){

            pair<int,int>p = make_pair(it->first,it->second);

            vec.push_back(p);

        }

        sort(vec.begin(),vec.end(),cmp);

        

        for(int i = 0; i < vec.size(); i++){

            count++;

            ans.push_back(vec[i].first);

            if(count == k){

                break;

            }

        }

        

        return ans;

    }

};
