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
        if (head == NULL) return NULL;
        stack<Node*> stck;
        stck.push(head);
        Node* curr=NULL, *prev=NULL, *newhead=NULL;
        while (!stck.empty()) {
            prev=curr;
            curr=stck.top(); stck.pop();
            if (curr->next) stck.push(curr->next);
            if (curr->child) stck.push(curr->child);
            curr->child=NULL;
            curr->prev=prev;
            if (prev) prev->next=curr;
            else newhead=curr;
        }
        return newhead;
    }
};
