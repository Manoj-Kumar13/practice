#include <bits/stdc++.h> 
/**********************************************************************

    Following is the class structure of the Node class for reference:

    class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

********************************************************************/
Node* findMid(Node* head){
    Node * fast = head->next;
    Node* slow = head;
    
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node* mergeLL(Node* left, Node* right){
    if(!left){
        return right;
    }
    if(!right){
        return left;
    }
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(left and right){
        if(left->data < right->data){
            temp->next = left;
            temp=left;
            left = left->next;
        }else{
            temp->next = right;
            temp=right;
            right = right->next;
        }
    }
    
    while(left){
        temp->next = left;
        temp=left;
        left = left->next;
    }
    
    while(right){
         temp->next = right;
         temp=right;
         right = right->next;
    }
    
    ans = ans->next;
    return ans;
}

Node *sortLL(Node *head){
    // Write your code here.
    if(!head or !head->next){
        return head;
    }
    Node* mid = findMid(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    left = sortLL(left);
    right = sortLL(right);
    
    Node* result = mergeLL(left,right);
    
    return result;
}
