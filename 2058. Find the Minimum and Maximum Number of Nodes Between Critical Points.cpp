/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        int c = 2;
        ListNode *a = head, *b = head->next;
        while(b->next){
            // Check for local maxima condition
            if(b->val > a->val && b->val > b->next->val){
                ans.push_back(c);
            }
            // check for local minima condition
            else if(b->val < a->val && b->val < b->next->val){
                ans.push_back(c);
            }
            a = b;
            b = b->next;
            c++;
        }
        if(ans.size() >= 2){
            sort(ans.begin(),ans.end());
            vector<int>bs; int value = INT_MAX;
            for(int i = 0; i < ans.size() - 1; i++){
                value = min(value,abs(ans[i] - ans[i+1]));
            }
            bs.push_back(value);
            // Maximum distance between two critical points
            bs.push_back(ans[ans.size()-1]-ans[0]);
            return bs;
        }
        else{
            ans = {-1,-1};
        }
        return ans;
    }
};
