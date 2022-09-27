#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class myGraph {
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u, int v, int weight){
        // direction == 0, undirected graph
        // direction == 1, directed graph
        pair<int,int> p = make_pair(v,weight); 
        // create an edge from a to b
        adj[u].push_back(p);
    }

    void printAdjList(){
        for(auto i: adj){
            cout << i.first <<" -> ";
            for(auto j : i.second){
                cout << "( " << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void dfsTopo(int node,unordered_map<int,bool> &visited, stack<int> &s){
        visited[node] =true;

        for(auto i: adj[node]){
            if(!visited[i.first]){
                dfsTopo(i.first,visited,s);
            }
        }

        s.push(node);
    }

    void greatestShortestPath(int src, vector<int> &dist, stack<int> &s){
        dist[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                for (auto i : adj[top])
                {
                    if(dist[top]+ i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
                
            }
        }
        
    }

};

int main(){

    // int n;
    // cout << "Enter NO. of nodes" << endl;
    // cin >> n;

    // int m;
    // cout << "Enter NO. of edges" << endl;
    // cin >> m;

    myGraph g;

      // add all edges to graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int n=6;

    unordered_map<int,bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            g.dfsTopo(i,visited,s);
        }
    }

    g.printAdjList();  
    
    int src =1;

    vector<int> dist(n);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    g.greatestShortestPath(src,dist,s);

    cout << "answer is : " ;

    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    
    


     
    return 0;
}
