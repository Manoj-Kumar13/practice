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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int n=0;
        vector<int> a;
        while(temp!=NULL){
            a.push_back(temp->val);
            temp = temp->next;
            n++;
        }
        
        int left = 0,right = n-1;
        
        while(left<=right){
            if(a[left]!=a[right]){
                return false;
            }
            left++;
            right--;
        }
        
        return true;
        
        
    }
};
