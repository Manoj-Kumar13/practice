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
    int helper(TreeNode* root, vector<int> &a){
        if(!root){
            return 0;
        }
        
        if(!root->left and !root->right){
            a[root->val]++;
            int cnt = 0;
            for(auto i : a){
                if(i&1){
                    cnt++;
                }
            }
            a[root->val]--;
            if(cnt>1){
                return 0;
            }
            return 1;
        }else{
            a[root->val]++;
            int ans = helper(root->left,a) + helper(root->right,a);
            a[root->val]--;
            return ans;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> ans(10);
        
        return helper(root,ans);
    }
};
