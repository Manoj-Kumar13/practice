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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        
        stack<ListNode*> s;
        int n=0;
        
        while(temp!=NULL){
            s.push(temp);
            temp = temp->next;
            n++;
        }
        
        temp = head;
        
        for(int i=0; i<n/2; i++){
            ListNode* elem = s.top();
            elem->next = temp->next;
            temp->next = elem;
            temp = temp->next->next;
            s.pop();
        }
        
        temp->next = NULL;
        
    }
};
