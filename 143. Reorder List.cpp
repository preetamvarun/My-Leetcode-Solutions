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
    void reorderList(ListNode* head) {
        
        if(head->next == NULL){
            return;
        }
        
        // Find the length of the linked list
        int len = 0;
        
        ListNode *le = head;
        
        while(le){
            len++;
            le = le->next;
        }
        
        // Create a new linked list => reverse(originalLinkedList)
        
        ListNode *x = head, *root = NULL, *y, *p, *q;
        
        while(x){
            ListNode *p = new ListNode();
            p->val = x->val;
            p->next = NULL;
            if(root == NULL){
                root = p;
            }
            else{
                p->next = root;
                root = p;
            }
            x = x->next;
        }
        
//         cout << "printing reversed linked list" << endl;
        
//         ListNode *temp = root;
//         while(temp){
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
        
        x = head;
        y = root;
        
        int c = len/2, d = len%2 ? 0 : 1;
        
        while(d != c){
            p = x->next;
            q = y->next;
            x->next = y;
            y->next = p;
            x = p;
            y = q;
            d++;
        }
        
        len%2 ?  x->next = NULL : x->next->next = NULL;
        
    }
};
