// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int child1 = 2*i+1;
        int child2 = 2*i+2;
        
        if(child1 < n and arr[largest] < arr[child1]){
            largest = child1;
        }
        if(child2 < n and arr[largest] < arr[child2]){
            largest = child2;
        }
        
        if(largest != i)
        {
            return false;
        }
        return true;
    }
    
    int countNode(struct Node* root ){
        if(!root){
            return 0;
        }
        
        return 1+countNode(root->left) + countNode(root->right);
    } 
    
    bool isCBT(struct Node* root, int index, int cnt){
        if(!root){
            return true;
        }
        
        if(cnt<=index){
            return false;
        }
        
        return (isCBT(root->left,2*index+1,cnt) and isCBT(root->right,2*index+2,cnt));
    }
    
   bool isMaxHeap(struct Node *root){
        if(!root->left and !root->right){
            return true;
        }
        
        if(!root->right){
            return (root->data > root->left->data);
        }else{
            return (isMaxHeap(root->left) and isMaxHeap(root->right) and root->data > root->left->data and 
                                                                        root->data > root->right->data);
        }
    }
    
    //better approach
    bool isHeap(struct Node* root) {
        
        if(!root){
            return true;
        }
        
        int cnt = countNode(root);
        
        if(isCBT(root,0,cnt) and isMaxHeap(root)){
            return true;
        }
        
        return false;
    }
    
    //another approach
    bool isHeap(struct Node* root) {
        // code here
        bool ans = true;
        vector<int> arr;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            arr.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        int n = arr.size();
        for(int i=n/2-1; i>=0; i--){
            ans = heapify(arr,n,i);
            if(ans == false){
                break;
            }
        }
        
        // return true;
        
        if(!root){
            return true;
        }
        
        int cnt = countNode(root);
        
        if(isCBT(root,0,cnt) and ans){
            return true;
        }
        
        return false;
    }
};
