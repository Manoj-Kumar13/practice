/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL ){
            return NULL;
        }
        
        ListNode* temp = head;
        ListNode* k = head;
        int i=-1;
        int len = 0;
        while(temp!=NULL){
            if(i<n){
                i++;
            }else{
                k = k->next;
            }
            len++;
            temp = temp->next;
        }
        if(len == n){
            return head->next;
        }
        if(k->next == NULL){
            k = NULL;
        }else{  
            k->next = k->next->next;
        }
        
        return head;
    }
};
