#include <bits/stdc++.h> 
class node {
    public: 
        int data;
        int i;
        int j;
    node(int val, int row , int col){
        data = val;
        i = row;
        j = col;
    }
};

class compare{
    public:
     bool operator()(node* a, node* b){
         return (a->data > b->data);
     }
    
};
vector<int> mergeKSortedArrays(vector<vector<int>>&a, int k)
{
    int n = a.size();
    priority_queue<node* , vector<node*>, compare> minHeap;
    vector<int> ans;
    // Write your code here.
    
    for(int i=0; i<n; i++){
        node* temp = new node(a[i][0], i, 0);
        minHeap.push(temp);
    }
    
    while(minHeap.size() > 0){
        node * temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);
        
        int i = temp->i;
        int j = temp->j;
        
        if(j+1 < a[i].size()){
            node * next = new node(a[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    
    return ans;
    
}
