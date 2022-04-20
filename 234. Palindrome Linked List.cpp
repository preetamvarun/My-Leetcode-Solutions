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
    bool isPalindrome(ListNode* head) {
        
        if(head->next == NULL){
            return true;
        }
        
        // Find the length of the linked list
        
        int len = 0; ListNode *x = head, *m = head, *dummyHead, *p, *q, *r;
        
        while(x){
            len++;
            x = x-> next;
        }     
        
        if(len == 2){
            return head->val == head->next->val;
        }
        
        // Find the middle node in the linked list 
        
        int count = 0, halfSize = len/2;
        
        while(count != halfSize){
            count++;
            m = m->next;
        }
        
        // Reverse the right half of the linked list
        
        dummyHead = len % 2 ? m->next : m;
        
        p = dummyHead;
        q = p->next;
        p->next = NULL;
        
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        
        dummyHead = p;
        
        // Compare the left half and right half (reversed part) of the linked list
        
        while(dummyHead){
            if(head->val != dummyHead->val) return false;
            head = head->next;
            dummyHead = dummyHead->next;
        }
        
        return true;
    }
};
