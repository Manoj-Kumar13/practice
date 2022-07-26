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
