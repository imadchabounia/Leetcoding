/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* go(Node* head){
        if(head == NULL) return NULL;
        if(head->next == NULL){
            head->next = head->child;
            Node* tail = go(head->child);
            if(tail != NULL) tail->prev = head;
            head->child = NULL;
            return head;
        }
        while(head->next != NULL){
            if(head->child == NULL){
                head = head->next;
            }else{
                Node* nxt = head->next;
                head->next = head->child;
                head->child->prev = head;
                Node* tail = go(head->child);
                head->child = NULL;
                if(nxt != NULL) nxt->prev = tail;
                if(tail != NULL) tail->next = nxt;
                head = nxt;
            }
        }
        return head;
    }
    
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        Node* n = go(head);
        return head;
    }
};
