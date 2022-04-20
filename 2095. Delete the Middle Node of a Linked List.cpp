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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        int len = 0, c = 0, d = 0;
        ListNode* x = head, *p = head, *q;
        while(x){
            x = x->next;
            len++;
        }
        c = len/2;
        while (c != d){
            q = p;
            p = p->next;
            d++;
        }
        q->next = p->next;
        p->next = NULL;
        delete(p);
        return head;
    }
};
