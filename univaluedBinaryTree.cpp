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
    bool isValid(TreeNode* root, int& val){
        if(!root){
            return true;
        }
        
        return root->val == val and isValid(root->left,val) and isValid(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root){
            return true;
        }
        
        int val = root->val;
        
        return isValid(root, val);
        
    }
};
