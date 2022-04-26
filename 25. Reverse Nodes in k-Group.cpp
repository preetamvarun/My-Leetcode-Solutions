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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        // Check whether you need to reverse the entire linked list
        int cnt = 0;
        // Find the length of the linked list
        ListNode *A = head;
        while(A){
            A = A->next;
            cnt++;
        }
        if(cnt == k){
            // Reverse the entire linked list
            ListNode *a = head, *b = head->next, *c = head->next;
            while(c->next){
                c = b->next;
                b->next = a;
                a = b;
                b = c;
              }
            b->next = a;
            head->next = NULL;
            head = b;
            return head;
        }
        ListNode *lastPtr;
        ListNode *p = head, *q = head;
        int c = 1;
        while(p){
            if(c == k){
                if(q == head && p->next != NULL){
                    lastPtr = head;
                    ListNode *a = head, *b = head->next, *g = head->next;
                    while(c != 1){
                        g = b->next;
                        b->next = a;
                        a = b;
                        b = g;
                        c--;
                    }
                    head->next = g;
                    head = a;
                    q = b;
                    p = b;
                }
                else if(q != head && p->next != NULL){
                    ListNode *a = q, *b = q->next, *g = q->next, *x;
                    while(c != 1){
                        g = b->next;
                        b->next = a;
                        a = b;
                        b = g;
                        c--;
                    }
                    x = lastPtr->next;
                    lastPtr->next = a;
                    x->next = g;
                    p = b;
                    q = b;
                    lastPtr = x;
                }
                else if(q != head && p->next == NULL){
                    ListNode *a = q, *b = q->next, *g = q->next, *x;
                    while(g->next){
                        g = b->next;
                        b->next = a;
                        a = b;
                        b = g;
                    }
                    x = lastPtr->next;
                    x->next = NULL;
                    lastPtr->next = g;
                    g->next = a;
                }
            }
            p = p->next;
            c++;
        }
        return head;
    }
};
