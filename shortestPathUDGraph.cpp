#include<bits/stdc++.h>

//using BFS approach
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    unordered_map<int, list<int>> adjList;
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    
    queue<int> q;
    
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        visited[frontNode] = true;
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                parent[i] = frontNode;
                visited[i] = true;
            }
        }
    }
    
    vector<int> ans;
    int currentNode = t;
    ans.push_back(currentNode);
    
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
	
}
