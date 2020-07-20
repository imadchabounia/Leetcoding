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
    
    using node = ListNode;
    
    ListNode* removeElements(ListNode* head, int val) {
        //using a dummy node
        if(head == NULL) return head;
        node* dummy = new node(0);
        dummy->next = head;
        node* curr = dummy;
        while(curr != NULL){
            node* tmp = curr->next;
            while(tmp != NULL && tmp->val == val){
                tmp = tmp->next;
            } 
            curr->next = tmp;
            curr = curr->next;
        }
        return dummy->next;
    }
};
