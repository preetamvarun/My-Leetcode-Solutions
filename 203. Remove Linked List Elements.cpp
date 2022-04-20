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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* p = head, *q;
        while(p){
            if(p->val == val){
                if(p == head){
                    head = p->next;
                    p->next = NULL;
                    delete(p);
                    p = head;
                }
                else if(p->next == NULL){
                    q->next = NULL;
                    delete (p);
                    break;
                }
                else {
                    q->next = p->next;
                    p->next = NULL;
                    delete (p);
                    p = q->next;
                }
            }
            else{
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};
