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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         if(root == NULL){
                vector<vector<int>>v;
            return v;
        }
        map<int,map<int,multiset<int>>>mapp;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{1,root}});
        while(!q.empty()){
            pair<int,pair<int,TreeNode*>>p = q.front();
            q.pop();
            int level = p.first;
            int nodeKalevel = p.second.first;
            TreeNode*temp = p.second.second;
            mapp[level][nodeKalevel].insert(temp->val);
            if(temp->left!=NULL){
               q.push({level - 1,{nodeKalevel + 1, temp->left}});
            }
             if(temp->right!=NULL){
                  q.push({level + 1,{nodeKalevel+ 1, temp->right}}); 
            }
        }
        vector<vector<int>>v(mapp.size());
        int l = 0;
        for(auto i :mapp){
            map<int,multiset<int>> pp = i.second;
            for(auto kkk :pp){
            multiset<int>a = kkk.second;
            for(auto j : a)
            v[l].push_back(j);
            }
           l++;
                
        }
        return v;
    }
};
