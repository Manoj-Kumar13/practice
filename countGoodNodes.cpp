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
    
    int dfs(TreeNode* root, int maxed){
        if(!root){
            return 0;
        }
        int ans = 0;
        if(root->val >= maxed){
            ans = 1;
        }
        
        ans += dfs(root->left,  max(root->val,maxed));
        ans += dfs(root->right, max(root->val,maxed));
        
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxed = INT_MIN;
        
        return dfs(root, maxed);
    }
};
