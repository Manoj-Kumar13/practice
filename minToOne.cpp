//With Memoization
int minToOne(int n,vector<int>& a){
	  if(n<=1){
        return 0;
    }

    if(a[n] != -1){
    	return a[n];
    }

    int x = minToOne(n-1,a);

    int y = INT_MAX, z= INT_MAX;
    if(n%2 == 0){
    	y = minToOne(n/2,a);
    }

    if(n%3 == 0){
    	z = minToOne(n/3,a);
    }

    a[n] =  min(x,(min(y,z)))+1;

    return a[n];	

}

//With Tabulation
int minToOneDP(int n, vector<int>& dp){
	if(n<=1){
		return dp[n];
	}

	for(int i=2; i<=n; i++){
		int x = i-1, y = i-1, z = i-1;
		if(i%2 == 0) {y = i/2;}
		if(i%3 == 0) {z = i/3;}

		dp[i] = min(dp[x],min(dp[y],dp[z]))+1;
	}

	return dp[n];
}

void solve(){
	int n;
	cin >> n;

	vector<int> a(n+1,-1);

	cout << minToOne(n,a) << endl;
}
