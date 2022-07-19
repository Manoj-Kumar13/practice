class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if(head == NULL or head->next ==NULL){
            return head;
        }
     // your code goes here
     map<int,bool> m;
     
     Node* temp = head;
     
     m[temp->data] = true;
     Node* prev = temp;
    
     while(temp != NULL){
          if (m[temp->data] == true){
           prev->next = temp->next;
          }else{
              prev = temp;
          }
          m[temp->data] = true;
          
          temp = temp->next;
         
     }
     
     return head;
    }
};
