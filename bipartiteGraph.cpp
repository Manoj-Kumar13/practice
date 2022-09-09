class Solution {
public:
    bool checkBpt(int node, vector<int> &color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        
        while(!q.empty()){
            int c = q.front();
            q.pop();
            
            for(auto i : graph[c]){
                if(color[i] == -1){
                    color[i] = 1- color[c];
                    q.push(i);
                }else if(color[i] != -1 and color[i] == color[c]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i] == -1 and !checkBpt(i,color,graph)){
                return false;
            }
        }
        
        return true;
    }
};
