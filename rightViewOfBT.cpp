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
    vector<int> rightSideView(TreeNode* root) {
        vector<pair<int,int>> ans;
        
        return helper(root,ans);
    }
    
    vector<int> helper(TreeNode* root, vector<pair<int,int>>& ans){
        if(root == NULL){
           vector<int>aa;
            return aa;
        }
        
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            ans.push_back({node->val,level});
          
            q.pop();
            
            if(node->left!= NULL){
                q.push({node->left,level+1});
            }
            
            if(node->right!= NULL){
                q.push({node->right,level+1});
            }
        }
        map<int,int>mapp;
        for(auto i :ans){
            mapp[i.second] = i.first;
        }
        vector<int>anss;
        for(auto i :mapp){
           anss.push_back(i.second); 
        }
        return anss;
        }
};
