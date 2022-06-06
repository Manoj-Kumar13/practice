/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        int n1 = 0,n2=0,diff=0;
        
        while(temp1!=NULL){
            temp1 = temp1->next;
            n1++;
        }
        
        while(temp2!=NULL){
            temp2 = temp2->next;
            n2++;
        }
        
        temp1 = headA;
        temp2 = headB;
        
        if(n1>n2){
            diff = n1-n2;
            while(diff--){
                 if(temp1 == NULL){
                    return NULL;
                }
                temp1 = temp1->next;
            }
        }else{
            diff = n2-n1;
            while(diff--){
                if(temp2 == NULL){
                    return NULL;
                }
                temp2 = temp2->next;
            }
        }
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return NULL;
        
        
    }
};
