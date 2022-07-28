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
    void getOrder(TreeNode* root, vector<int>& order){
        if(!root){
            return;
        }
        
        if(!root->left and !root->right){
            order.push_back(root->val);
        }
        if(root->left){
            getOrder(root->left, order);
        }
        if(root->right){
            getOrder(root->right,order);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> order1;
        vector<int> order2;
        
        getOrder(root1, order1);
        getOrder(root2,order2);
        
        int s1 = order1.size();
        int s2= order2.size();
        
        if(s1 == s2){
            for(int i=0; i<s1; i++){
                if(order1[i] != order2[i]){
                    return false;
                }
            }
        }else{
            return false;
        }
        
        return true;
    }
};
