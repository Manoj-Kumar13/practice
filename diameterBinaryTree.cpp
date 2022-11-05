//if diameter consists of no. of edges b/w nodes 
int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int d = 0;
        getD(root,d);
        return d;
    }
    
     int getD(TreeNode* root, int& d) {
        if(!root){
            return 0;
        }
        int ld = getD(root->left,d);
        int rd = getD(root->right,d);
         
        d = max(d,ld+rd);
         
        return 1 + max(ld,rd);
    }

//another approach
 int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return max((lh+rh), max(ld,rd));
    }
    
     int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }

//another appraoch (if diameter consists of no. of nodes)
int solve(Node* root, int &res){
    if(!root){
        return 0;
    }
    
    int lh = solve(root->left, res);
    int rh = solve(root->right, res);
    
    int temp = 1 + max(lh,rh);
    int tempAns =  1 + lh + rh;
    
    res = max(res,tempAns);
    
    return temp;
}

class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        vector<vector<int>> dp();
        int res = 0;
        solve(root,res);
        return res;
    }
};
