/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include<bits/stdc++.h>
class compare{
    public:
     bool operator()(Node<int>* a, Node<int>* b){
         return (a->data > b->data);
     }
    
};
Node<int>* mergeKLists(vector<Node<int>*> &a)
{
    // Write your code here.
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;
    
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    int k = a.size();
    for(int i=0; i<k; i++){
        if(a[i]!=NULL){
            minHeap.push(a[i]);
        }
    }
    
    while(minHeap.size()>0){
        Node<int>* top = minHeap.top();
        minHeap.pop();
        
        if(top->next != NULL){
            minHeap.push(top->next);
        }
        
        if(head == NULL){
            head = top;
            tail = top;
        }else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
