class Solution {
public:
    
   static bool comparator(string a, string b){
        
        if(a.size() != b.size()){
            return a.size() > b.size();
        }
        
        return a > b;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comparator);
        
        return nums[k-1];
    }
};
