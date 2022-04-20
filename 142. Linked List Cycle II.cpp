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
    ListNode *detectCycle(ListNode *head) {
        ListNode *tortoise = head, *hare = head, *flag = NULL;
        while(hare && hare->next){
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(tortoise == hare){
                flag = tortoise;
                break;
            }
        }
        if(flag == NULL){
            return NULL;
        }
        else{
            tortoise = head;
            while(hare != tortoise){
                tortoise = tortoise->next;
                hare = hare->next;
            }
        }
        return tortoise;
    }
};
