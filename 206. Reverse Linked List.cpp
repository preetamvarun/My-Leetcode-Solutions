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
    ListNode* reverseList(ListNode* head) {
        int len = 0;
        ListNode *t = head;
        while(t){
            t = t->next;
            len++;
            if(len > 1){
                break;
            }
        }
        if(len <= 1) return head;
        ListNode *p,*q,*r;
        p = head;
        q = p->next;
        r = q;
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        // q->next = p;
        // head->next = NULL;
        // head = r;
        head->next = NULL;
        head = p;
        return head;
    }
};
