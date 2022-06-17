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
    int ans = 0;
    int hasCamera = 0;
    int noCamera = 1;
    int covered = 2;
    
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == noCamera) ans++;
        return ans;
    }
    
    int dfs(TreeNode* root){
        if(!root){
            return covered;
        }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == noCamera || right == noCamera){
            ans++;
            return hasCamera;
        }
        if(left == hasCamera || right == hasCamera){
            return covered;
        }else{
            return noCamera;
        }
    }
};
