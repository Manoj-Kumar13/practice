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

// ques link for above : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// return in the form of an array
class Solution {
public:
    vector<int> helper(vector<int>& nums, int left, int right,vector<int> &ans){
        if(left>right){
            return ans;
        }
        
        int mid = left + (right-left)/2;
        
        ans.push_back(nums[mid]);
        
        helper(nums, left, mid-1, ans);
        helper(nums, mid+1, right, ans);
        
        return ans;
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> ans;
        return helper(nums, 0 , nums.size()-1, ans);
    }
};

// ques link for above : https://practice.geeksforgeeks.org/problems/array-to-bst4443/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
