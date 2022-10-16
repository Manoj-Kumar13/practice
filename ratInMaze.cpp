#include <bits/stdc++.h>
bool isSafe(int x, int y, vector<vector<int>> &arr, int &n, vector<vector<bool>> &visited){
    if(x>=0 and y>=0 and x<n and y<n and visited[x][y] == false and arr[x][y] == 1){
        return true;
    }else{
        return false;
    }
}

void solve(int x,int y, vector<vector<int>> &arr,vector<string> &ans, vector<vector<bool>> &visited,string path, int &n){
    if(x == n-1 and y == n-1){
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = true;
    // down
    if(isSafe(x+1,y, arr,n,visited)){
        path += "D";
       solve(x+1,y,arr,ans,visited, path,n);
        path.pop_back();
    }
     //left
    if(isSafe(x,y-1, arr,n,visited)){
        path += "L";
       solve(x,y-1,arr,ans,visited, path,n);
        path.pop_back();
    }
     //right
    if(isSafe(x,y+1, arr,n,visited)){
        path += "R";
       solve(x,y+1,arr,ans,visited, path,n); 
        path.pop_back();
    }
    //up
    if(isSafe(x-1,y, arr,n,visited)){
        path += "U";
       solve(x-1,y,arr,ans,visited, path,n);
        path.pop_back();
    }
    
    visited[x][y] = false;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    if(arr[0][0] == 0){
        return ans;
    }
    vector<vector<bool>> visited(n, vector<bool>(n,false));
    string path = "";
    
    solve(0,0, arr, ans, visited, path, n);
    
    return ans;
}
