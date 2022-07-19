class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        
        if(del->next == NULL){
            free(del);
            return;
        }
       // Your code here
       Node* temp = del->next;
       
       del->data = temp->data;
       
       del->next = temp->next;
       
       free(temp);
    }

};
