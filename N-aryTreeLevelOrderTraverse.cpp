/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<Node*> q;
        
        q.push(root);
        
        vector<int> tempArr;
        
        tempArr.push_back(root->val);
        
        ans.push_back(tempArr);
        
        
        while(!q.empty()){
            
            int s = q.size();
            vector<int> a;
            for(int i=0; i<s; i++){
                Node* temp = q.front();
                q.pop();
                for(int j=0; j<temp->children.size(); j++){
                    a.push_back(temp->children[j]->val);
                    q.push(temp->children[j]);
                }    
            }
            
            if(a.size()){
                ans.push_back(a);    
            }
            
        }
        
        return ans;
    }
};
