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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
       return helper(nums,0,nums.size()-1);
    }
    
    TreeNode* helper(vector<int> a,int low,int high){
        if(low>high){
            return NULL;
        }
        
        int mid = (low+high)/2;
        
        TreeNode* root = new TreeNode(a[mid]);
        
        root->left = helper(a,low,mid-1);
        root->right = helper(a,mid+1,high);
        
        return root;
        
    }
};
