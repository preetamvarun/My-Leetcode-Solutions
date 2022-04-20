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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p = list1, *q = list1;
        int c = 1;
        while(c != a){
            p = p->next;
            c++;
        }
        c = 0;
        while(c != b){
            q = q->next;
            c++;
        }
        p->next = list2;
        // Travel to the end of the list2
        ListNode *end = list2;
        while(end->next){
            end = end->next;
        }
        end->next = q->next;
        q->next = NULL;
        return list1;
    }
};
