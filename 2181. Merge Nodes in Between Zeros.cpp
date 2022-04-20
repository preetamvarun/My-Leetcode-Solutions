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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p,*q,*num;
        int sum = 0;
        p = head;
        q = head->next;
        num = q;
        while(q){
            if(q->val != 0){
                sum += q->val;
                num->val = sum;
            }
            else {
                num->next = q;
                sum = 0;
                num = q->next;
            }
            q = q->next;
        }
        while(true){
            if(head->val == 0){
                head = head->next;
                p = head;
            }
            else if(p->next->next == NULL){
                p->next = NULL;
                break;
            }
            else if(p->val != 0){
                q = p;
                p = p->next;
            }
            else if(p->val == 0){
                q->next = p->next;
                p = p->next;
            }
        }
        return head;
    }
};
