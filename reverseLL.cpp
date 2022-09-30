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
    ListNode* reverseList(ListNode* head) {
       if(!head){
           return head;
       }
        
        if(!head->next){
            return head;
        }
        
        ListNode* rl = reverseList(head->next);
        ListNode* temp = rl;
        
        while(temp->next!=NULL){
            temp = temp->next;
        }
        
        temp->next = head;
        head->next = NULL;
        return rl;
    }
};

//iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
