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
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root){
            return ans;
        }
        helper( root, ans, to_string(root->val));
        
        return ans;
    }
    
    void helper(TreeNode* root, vector<string>& ans, string val){
        if(!root->left and !root->right){
            ans.push_back(val);
            return ;
        }
        
        if(root->left){
            helper(root->left, ans, val + "->" + to_string(root->left->val));
        }
        if(root->right){
            helper(root->right, ans, val + "->" + to_string(root->right->val));
        }
        
    }
};
