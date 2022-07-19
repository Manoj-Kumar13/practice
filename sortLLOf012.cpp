class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* temp = head;
        int zeroes=0, ones=0,twos=0;
        
        while(temp!=NULL){
            int val = temp->data;
            if(val == 0){
                zeroes++;
            }else if(val == 1){
                ones++;
            }else{
                twos++;
            }
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp!=NULL){
            if(zeroes>0){
                temp->data = 0;
                zeroes--;
            }else if(ones>0){
                temp->data = 1;
                ones--;
            }else{
                temp->data = 2;
                twos--;
            }
            temp = temp->next;
        }
        
        return head;
    }
};
