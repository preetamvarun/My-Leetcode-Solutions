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
    int pairSum(ListNode* head) {
        int len = 0;
        ListNode *ptr = head, *p, *q, *r, *start = head;
        while(ptr){
            ptr = ptr->next;
            len++;
        }
        if(len == 2){
            return head->val+head->next->val;
        }
        int c = len/2, d = 0;
        ptr = head; 
        while(d != c){
            ptr = ptr->next;
            d++;
        }
        p = ptr;
        q = ptr->next;
        r = q;
        while(r->next){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        ptr->next = NULL;
        q->next = p;
        ptr = r;
        int ans = 0;
        while(r->next){
            ans = max(ans,start->val + r->val);
            start = start->next;
            r = r->next;
        }
        ans = max(ans,start->val + r->val);
        return ans;
    }
};
