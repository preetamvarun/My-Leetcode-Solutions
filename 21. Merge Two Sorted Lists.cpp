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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Firstly, find the length of the two linked lists
        
        int l1 = 0, l2 = 0;
        ListNode* x1 = list1;
        ListNode* x2 = list2;
        while(x1){
            l1++;
            x1 = x1->next;
        }
        while(x2){
            l2++;
            x2 = x2->next;
        }
        if(l1 == 0){
            return list2;
        }
        if(l2 == 0){
            return list1;
        }
        
        ListNode *p,*q,*r,*s;
        
       if(l1 >= l2){
            p = list1; r = list2;
            q = NULL;
        }
        
        else{
            p = list2; r = list1; 
            q = NULL;
        }
            while(p){
                if(r->val > p->val){
                    q = p;
                    p = p->next;
                }
                else{
                    if(q == NULL){
                        s = r->next;
                        r->next = p;
                        l1 >= l2 ? list1 = r : list2 = r;
                        p = r;
                        r = s;
                    }
                    else{
                        q->next = r;
                        s = r->next;
                        r->next = p;
                        r = s;
                        q = q->next;
                    }
                }
                if(r == NULL){
                    break;
                }
            }
            if(r != NULL){
                q->next = r;
            }
        return l1>=l2 ? list1 : list2;
    }
};
