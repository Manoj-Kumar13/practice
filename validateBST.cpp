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
    TreeNode* prev = NULL;
    bool helper(TreeNode* root, long MinVal, long MaxVal){
        if(!root){
            return true;
        }
        
        if(root->val < MinVal+1 or root->val > MaxVal-1){
            return false;
        }
        
        return helper(root->left, MinVal, root->val) and helper(root->right, root->val, MaxVal);
    }
    
    
    bool isValidBST(TreeNode* root) {
        // return helper(root, LONG_MIN,LONG_MAX);
        if(root){
            if(!isValidBST(root->left)){
                return false;
            }
            
            if(prev and prev->val >= root->val){
                return false;
            }
            prev = root;
            
            return isValidBST(root->right);
        }
        return true;
    }
};
