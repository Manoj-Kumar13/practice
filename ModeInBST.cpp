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
    int cnt = 1;
    int max = 0;
    int prev = INT_MIN;
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        
        traverse(root,modes);
        
        int n = modes.size();
        
        vector<int> result;
        
        for(int i = 0; i< n; i++){
            result.push_back(modes[i]);
        }
        
        return result;
    }
    
    void traverse(TreeNode* root, vector<int> &modes){
        if(root == NULL){
            return;
        }
        
        traverse(root->left,modes);
        
            if(prev == root->val){
                cnt++;
            }else{
                cnt = 1;
            }
        
        if(cnt>max){
            max = cnt;
            modes.clear();
            modes.push_back(root->val);
        }else if(cnt == max){
            modes.push_back(root->val);
        }
        
        prev = root->val;
        
        traverse(root->right,modes);
    }
    
};
