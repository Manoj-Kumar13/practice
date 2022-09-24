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
    
    void helper(TreeNode* root, int t,vector<int> temp, vector<vector<int>> &ans){
        if (!root){
            return;
        }
        
        temp.push_back(root -> val);
        
        if (!(root->left) && !(root-> right) && t == root->val){
            ans.push_back(temp);
        }
        
        helper(root -> left, t-root->val, temp, ans);
        
        helper(root->right, t-root->val, temp, ans);
        
        temp.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(!root){
            return ans;
        }
        helper(root, target,temp, ans);
        return ans;
    }
};
