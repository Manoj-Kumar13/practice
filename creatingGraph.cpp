#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class myGraph {
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int a, int b, int direction){
        // direction == 0, undirected graph
        // direction == 1, directed graph
        
        // create an edge from a to b
        adj[a].push_back(b);

        if(direction == 0){
            adj[b].push_back(a);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout << i.first <<" -> ";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){

    int n;
    cout << "Enter NO. of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter NO. of edges" << endl;
    cin >> m;

    myGraph g;

    for (int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        // creating an undirected graph
        g.addEdge(a,b,0);
    }

    g.printAdjList();   
     
    return 0;
}
