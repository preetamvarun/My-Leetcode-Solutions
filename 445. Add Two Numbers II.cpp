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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Find the length of both the linked lists
        int len1 = 0, len2 = 0;
        ListNode *a = l1, *b = l2, *p, *q, *r, *A, *B;
        while(a){
            len1++;
            a = a->next;
        }
        while(b){
            len2++;
            b = b->next;
        }
        while(len1 > len2){
            // Create a new node whose value is zero
            ListNode *zero = new ListNode();
            zero->val = 0;
            zero->next = l2;
            l2 = zero;
            len2++;
        }
        while(len2 > len1){
            ListNode *zero = new ListNode();
            zero->val = 0;
            zero->next = l1;
            l1 = zero;
            len1++;
        }
        // Now reverse both the linked lists
        
        p = l1, q = p->next, r = q;
        
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        
        l1->next = NULL;
        l1 = p;
        
        p = l2, q = p->next, r = q;
        
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        
        l2->next = NULL;
        l2 = p;
        
        A = l1, B = l2;
        
        while(A->next) A = A->next;
        while(B->next) B = B->next;
        
        p = l1, q = l2; 
            
        int sum, carry = 0;
        
        while(p){
            sum = p->val + q->val + carry;
            if(sum >= 10){
                carry = 1;
                p->val  = sum % 10;
            }
            else{
                carry = 0;
                p->val = sum;
            }
            p = p->next;
            q = q->next;
        }
        
        if(carry){
            ListNode *x = new ListNode();
            x->val = 1;
            x->next = NULL;
            A->next = x;
        }
        
        p = l1, q = l1->next, r = q;
        
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        l1->next = NULL;
        l1 = p;
        
        return l1;
    }
};
