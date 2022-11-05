class Solution {
public:
    long long solve(TreeNode* root, int &res){
        if(!root){
            return 0;
        }
        
        int ls = solve(root->left, res);
        int rs = solve(root->right,res);
        
        int temp = max(max(ls,rs)+root->val,root->val);
        int tempAns = max(temp, ls + rs + root->val);
        res = max(res,tempAns);
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        if(!root){
            return 0;
        }
        return res;
    }
};
