#include<bits/stdc++.h>
#include<limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int,int>>> adjList;
    
    for(int i=0; i<g.size(); i++){
        int a = g[i].first.first;
        int b = g[i].first.second;
        int w = g[i].second;
        adjList[a].push_back(make_pair(b,w));
        adjList[b].push_back(make_pair(a,w));
    }
    
    vector<int> parent(n+1);
    vector<bool> mst(n+1);
    vector<int> key(n+1);
    
    for(int i=0; i<=n; i++){
        mst[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    
    key[1] = 0;
    parent[1] = -1;
    
    for(int count = 1; count < n; count++){
        int mini = INT_MAX,u;
        
        for(int v=1; v<=n; v++){
            if(mst[v] == false and key[v]<mini){
                mini = key[v];
                u = v;
            }
        }
        
        mst[u] = true;    
        
        for(auto i : adjList[u]){
            int v = i.first;
            int w = i.second;
            if(mst[v] == false and w< key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    
    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    
    return ans;
}
