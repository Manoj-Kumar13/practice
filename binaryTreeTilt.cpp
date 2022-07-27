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
    int helper(TreeNode* root,int& diff){
        if(!root){
            return 0;
        }
        
        if(!root->left and !root->right){
            return root->val;
        }
        
        int ld = helper(root->left, diff);
        int rd = helper(root->right, diff);
        
        diff += abs(ld-rd);
        
        return ld+rd+root->val;
    }
    int findTilt(TreeNode* root) {
        if(!root){
            return 0;
        }
        int diff = 0;
        helper(root,diff);
        return diff;
    }
};
