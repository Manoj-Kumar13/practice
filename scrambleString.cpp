unordered_map<string,bool> dp;
int Solution::isScramble(const string a, const string b) {
    if(a.compare(b) == 0){
        return true;
    }
    int n = a.length();
    if(a.length() <= 1){
        return false;
    }
    string key = a + " " + b;
    if(dp.find(key) != dp.end()){
        return dp[key];
    }
    
    bool flag = false;
    for(int i=1; i<n; i++){
        if(isScramble(a.substr(0,i),b.substr(n-i,i)) and isScramble(a.substr(i,n-i),b.substr(0,n-i))){
            flag = true;
            break;
        }
        if(isScramble(a.substr(0,i),b.substr(0,i)) and isScramble(a.substr(i,n-i),b.substr(i,n-i))){
            flag = true;
            break;
        }
    }
    
    return dp[key] = flag;
}
