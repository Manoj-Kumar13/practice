vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n = a.size();
    vector<bool> temp(n,false);
    vector<int> ans;
    
    for(int i=0; i<n ; i++){
        if(temp[a[i]]){
            ans.push_back(a[i]);
        }
        temp[a[i]] = true;
    }
    
    for(int i=1; i<=n; i++){
        if(temp[i] == false){
            ans.push_back(i);
        }
    }
    
    return ans;
}
