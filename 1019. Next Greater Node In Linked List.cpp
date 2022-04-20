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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v,ans;
        ListNode *p = head;
        while(p){
            v.push_back(p->val);
            p = p->next;
        }
        stack<int>s;
        for (int i = v.size()-1; i>=0; i--){
            if (s.size() == 0){
                s.push(v[i]);
                ans.push_back(0);
            }
            else{
                bool flag = true;
                while(v[i] >= s.top()){
                    s.pop();
                    if(s.size() == 0){
                        flag = false;
                        ans.push_back(0);
                        break;
                    }
                }
                if(flag) ans.push_back(s.top());
                s.push(v[i]);
            }
        }
        reverse (ans.begin(),ans.end());
        return ans;
    }
};