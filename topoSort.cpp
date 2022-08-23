#include<bits/stdc++.h>
void topoSort(int node,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adjList){
    visited[node] = true;
    
    for(auto i: adjList[node]){
        if(!visited[i]){
            topoSort(i,visited,s,adjList);
        }
    }
    
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adjList;
    for(int i=0; i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    vector<bool> visited(v);
    
    stack<int> s;
    
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topoSort(i,visited,s,adjList);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
    
    
}
