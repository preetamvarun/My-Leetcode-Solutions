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
    ListNode* swapPairs(ListNode* head) {
        // Find the length of the linked list
        int len = 0;
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *x = head, *p = head, *q = head->next, *r = head->next->next;
        while(x){
            len++;
            x = x->next;
        }
        head = q;
        
        // IF The Length Is Even
        if(len % 2 == 0){
            while(r){
                q->next = p;
                p->next = r->next;
                p = r;
                q = p->next;
                r = q->next;
            }
            q->next = p;
            p->next = NULL;
        }
        
        // If the length is odd 
        
        else{
            while(r->next){
                q->next = p;
                p->next = r->next;
                p = r;
                q = p->next;
                r = q->next;
            }
            p->next = r;
            q->next = p;
        }
        
        return head;
    }
};
