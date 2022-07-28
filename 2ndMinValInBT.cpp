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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        
        preOrder(root,s);
        
        if(s.size()<2){
            return -1;
        }
        
        int step = 2;
        int ans = -1;
        for(auto val : s){
            if(step==0){
                break;
            }
            ans = val;
            step--;
        }
        return ans;
    }
    
    void preOrder(TreeNode* root, set<int>&s){
        if(!root){
            return;
        }
        
        s.insert(root->val);
        preOrder(root->left,s);
        preOrder(root->right,s);
        
    }
};
