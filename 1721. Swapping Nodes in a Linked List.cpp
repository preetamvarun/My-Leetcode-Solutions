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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head, *q = head;
        int c = 1;
        while(c != k){
            p = p->next;
            c++;
        }
        int len = 0;
        while(q){
            q = q->next;
            len++;
        }
        q = head;
        int d  = len-k; c = 0;
        while(c != d){
            q = q->next;
            c++;
        }
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        return head;
    }
};
