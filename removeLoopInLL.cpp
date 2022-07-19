#include<bits/stdc++.h>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
            if(head == NULL){
            return ;
        }
        Node*slow = head;
        Node*fast = head;
        do{
            if(slow == NULL || fast == NULL || fast->next == NULL){
                return ;
            }
            slow = slow ->next;
            fast = fast ->next->next;
            if(slow == fast){
                break;
            }
        }while(slow!=fast);
        
        Node*entry = head;
        
        if(entry == slow){
           while(entry->next!=slow){
               entry = entry->next;
           }
           entry->next = NULL;
           return;
        }
        
        while(entry->next!=slow->next){
            entry = entry->next;
            slow = slow->next;
        }
        slow->next = NULL;
        

    }
};
