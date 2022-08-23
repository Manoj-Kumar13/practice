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

//BFS approach
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size(); i++){
        int u = edges[i].first ;
        int v = edges[i].second ;
        
//         or int u = edges[i].first - 1;
//            int v = edges[i].second -1;
        
        adjList[u].push_back(v);
    }
    
    vector<int> indegree(n+1);
//     or vector<int> indegree(n);
    
    //find indegree of all elements
    for(auto i: adjList){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    
    queue<int> q;
    
    //push all elements with 0 indegree
    for(int i=1; i<=n; i++){
//         or for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        //increment the count
        cnt++;
        
        for(auto i : adjList[frontNode]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    
    if(cnt == n){
        return false;
    }
    return true;
}
