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
    ListNode* deleteDuplicates(ListNode* head) {
        
        // cout << head;
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        // if(head->next == NULL){
        //     return head;
        // }
        
        ListNode *p = head, *q = head->next, *r;
        
        while(true){
            if(p->val == q->val && q != NULL){
                if(q->next != NULL){
                    r = q->next;
                    q->next = NULL;
                    q = r;
                    p->next = q;
                }
                else{
                    p->next = NULL;
                    break;
                }
            }
            else if(p->val == q->val && q->next == NULL){
                p->next = NULL;
                break;
            }
            else if(p->val != q->val && q->next == NULL){
                break;
            }
            else{
                p = q;
                q = q->next;
            }
             
        }
        
        return head;
    }
};
