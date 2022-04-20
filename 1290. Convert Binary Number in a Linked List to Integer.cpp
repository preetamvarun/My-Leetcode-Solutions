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
    int getDecimalValue(ListNode* head) {
        vector<int>bits; int ans = 0, c = 0;
        while(head){
            bits.push_back(head->val);
            head = head->next;
        }
        for(int i = bits.size()-1; i >=0; i--){
            ans += (bits[i] * pow(2,c));
            c++;
        }
        return ans;
    }
};
