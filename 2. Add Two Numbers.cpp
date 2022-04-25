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
        // Find the length of both linked lists
        ListNode *a = l1, *b = l2,*A,*B;
        int len1 = 0, len2 = 0;
        while(a){
            A = a;
            a = a->next;
            len1++;
        }
        while(b){
            B = b;
            b = b->next;
            len2++;
        }
        while(len1 > len2){
            // Create a new node with value zero and append it to l2
            ListNode *x = new ListNode();
            x->val = 0;
            x->next = NULL;
            B->next = x;
            B = B->next;
            len2++;
        }
        while(len2 > len1){
            // Create a new node with value zero and append it to l1
            ListNode *x = new ListNode();
            x->val = 0;
            x->next = NULL;
            A->next = x;
            A = A->next;
            len1++;
        }
        ListNode *p = l1, *q = l2; int sum, carry = 0;
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
        return l1;
    }
};
