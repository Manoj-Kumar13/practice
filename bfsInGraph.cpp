#include<unordered_map>
#include<list>
#include<queue>
#include<set>
void prepareAdjList(vector<pair<int, int>> &edges, unordered_map<int,set<int>>&adjList){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void printAdjList(unordered_map<int,set<int>> &adjList){
    for(auto i: adjList){
        cout << i.first << "->";
        for(auto j: i.second){
            cout << j << ", ";
        }
        cout << endl;
    }
}

void bfs(unordered_map<int,set<int>> &adjList,vector<int> &ans,unordered_map<int,bool> &visited,int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
             q.push(i);
            visited[i] = true;   
            }
        }
    }
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,set<int>> adjList;
    
    prepareAdjList(edges,adjList);
    
//     printAdjList(adjList);
    
    unordered_map<int,bool> visited;
    
    vector<int> ans;
    
    //traverse all comp of graph
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList,ans,visited,i);
        }
    }
    
    return ans;
}
