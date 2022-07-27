 void helper(TreeNode* root, TreeNode*& prev){
        if(!root){
            return;
        }
        helper(root->right,prev);
        helper(root->left, prev);
        root->left = NULL;
        root->right = prev;
        prev = root;
        
    }
    
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        TreeNode* prev = NULL; 
        helper(root,prev);
    }
