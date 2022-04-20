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
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        map<int,int>mp;
        ListNode *x = head, *y = NULL;
        while(x){
            mp[x->val]++;
            x = x->next;
        }
        x = head;
        
        if(mp.size() == 1){
            head = NULL;
            return head;
        }
        
        while(x){
            if(mp[x->val] > 1){
                if(x->next != NULL){
                    if(y != 0){
                        y->next = x->next;
                        x->next = NULL;
                        x = y->next;
                    }
                   else if(y == 0){
                       x = x->next;
                       head = x;
                   }
                }
                else{
                    if(y != 0){
                        y->next = NULL;
                    }
                    else if(y == 0){
                        head = NULL;
                    }
                    break;
                }
            }
            else{
                y = x;
                x = x->next;
            }
        }
        return head;
    }
};
