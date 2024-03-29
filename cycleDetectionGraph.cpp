#include<bits/stdc++.h>

//bfs appraoch
bool bfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,int node){
    unordered_map<int,int> parent;
    queue<int> q;
    parent[node] = -1;
    visited[node] = true;
    
    q.push(node);
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto i: adjList[frontNode]){
            if(visited[i] and i != parent[frontNode]){
                return true;
            }else if(!visited[i]){
                visited[i] = true;
                q.push(i);
                parent[i] = frontNode;
            }
        }
    }
    return false;
}

//dfs approach
bool dfs(int node,int parent,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited){
    visited[node] = true;
    
    for(auto i: adjList[node]){
        if(!visited[i]){
            bool isCycle = dfs(i,node,adjList,visited);
            if(isCycle){
                return true;
            }
        }else if(i != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adjList;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = bfs(adjList,visited,i);
//             bool ans = dfs(i,-1,adjList,visited);
            if(ans){
                return "Yes";
            }
        }
    }
    
    return "No";
}
