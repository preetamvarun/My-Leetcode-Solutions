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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int storeLeft = left;
        
        if(left == right){
            return head;
        }

        ListNode *leftPointer = head, *rightPointer = head, *prev = NULL;
        
        while(left > 1){
            prev = leftPointer;
            leftPointer = leftPointer->next;
            left--;
        }
        
        while(right > 1){
            rightPointer = rightPointer->next;
            right--;
        }
        
        ListNode *p = leftPointer, *q = leftPointer, *r = leftPointer->next;
        
        while(r != rightPointer){
            q = r;
            r = r->next;
            q->next = p;
            p = q;
        }
        
        r = rightPointer->next;
        rightPointer->next = p;
        storeLeft != 1 ?  prev->next = rightPointer : head = rightPointer;
        leftPointer->next = r;
        
        return head;
    }
};
