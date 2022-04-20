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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL){
            return false;
        }
        
        if(head->next == NULL){
            return false;
        }
        
        // Keep two pointers : fast & slow
        // fast pointer moves twice as fast as slow pointer
        // they both meet at a point if there is a loop in the linked list
        
        
        // Both the fast and slow pointers start at the same position i.e., head
        
        ListNode *fast = head, *slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        
        return false;
    }
};
