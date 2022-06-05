/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        
        InorderTraversal(root,a);
        int n = a.size();
        
        for(int i=0,j=n-1; i<j;){
            int sum = a[i]+a[j];
            if(sum == k){
                return true;
            }
            
            sum>k?j--:i++;
        }
        
        return false;
    }
    
    void InorderTraversal(TreeNode* root, vector<int>& a){
        if(root == NULL){
            return;
        }
        
        InorderTraversal(root->left,a);
        a.push_back(root->val);
        InorderTraversal(root->right,a);
        
    }
    
};
