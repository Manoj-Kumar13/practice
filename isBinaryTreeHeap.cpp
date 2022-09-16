//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

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
    
    // bool isMaxHeap(struct Node *root){
    //     if(!root->left and !root->right){
    //         return true;
    //     }
        
    //     if(root->left->data > root->data and !root->right){
    //         return false;
    //     }else if(root->left->data > root->data or root->right->data > root->data){
    //         return false;
    //     }else{
    //         return (isMaxHeap(root->left) and isMaxHeap(root->right));
    //     }
    // }
    
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

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends
