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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *p = head, *q = head, *r = head;
        
        // Before going into the main logic make sure to remove all the nodes
        // whose value is zero
        
        while(p){
            if(p->val == 0){
                if(p == head){
                    head = p->next;
                    p = head;
                    q = head;
                }
                else if(p->next == NULL){
                    q->next = NULL;
                    break;
                }
                else{
                    q->next = p->next;
                    p->next = NULL;
                    p = q->next;
                }
                
            }
            else{
                q = p;
                p = p->next;
            }
        }
        
        int sum = 0; p = head; q = head;

         while(p){
            sum += q->val;
            if(sum == 0){
                if(p == head){
                    head = q->next;
                    p = head;
                    q = p;
                    if(head == NULL) return head;
                }
                else{
                    r->next = q->next;
                    q->next = NULL;
                    q = r->next;
                    p = q;
                    if(r->next == NULL){
                        return head;
                    }
                }
            }
            else q = q->next;
            if(q == NULL){
                r = p;
                p = p->next;
                q = p;
                sum = 0;
            }
        }
        
        return head;
    }
};
