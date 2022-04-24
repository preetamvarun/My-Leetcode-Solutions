/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a){
            len1++;
            a = a->next;
        }
        while(b){
            len2++;
            b = b->next;
        }
        ListNode *A = headA, *B = headB;
        if(len1 > len2){
            while(len1 > len2){
                A = A->next;
                len1--;
            }
        }
        else if(len2 > len1){
            while(len2 > len1){
                B = B->next;
                len2--;
            }
        }
        while(A){
            if(A == B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
};
