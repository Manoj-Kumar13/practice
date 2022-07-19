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
    Node* flatten(Node* head) {
        Node* tail = head;
        Node* temp = head;
        
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        Node* curChild;
        while(temp!=NULL){
            
            if(temp->child){
                curChild = temp->child;
                
                while(curChild!=NULL){
                    tail->next = curChild;
                    curChild = curChild->next;
                    tail = tail->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};
