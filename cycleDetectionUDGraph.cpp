#include<bits/stdc++.h>
bool DfsCycle(int node,unordered_map<int, bool> &visited,unordered_map<int, bool> &DFSvisited,unordered_map<int,list<int>> &adjList){
    visited[node] = true;
    DFSvisited[node] = true;
    
    for(auto i : adjList[node]){
        if(!visited[i]){
            bool isCycle = DfsCycle(i,visited,DFSvisited,adjList);
            if(isCycle){
                return true;
            }
        }else if(DFSvisited[i]){
            return true;
        }
    }
    
    DFSvisited[node] =false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool isCycle = DfsCycle(i,visited,DFSvisited,adjList);
            if(isCycle){
                return true;
            }
        }
    }
    return false;
}
