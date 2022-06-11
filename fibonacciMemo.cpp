int fiboWithDP(int n,vector<int>& a){
	if(n<=1){
        return n;
    }
    
    if(a[n] != -1){
        return a[n];
    }

    a[n] = fiboWithDP(n-1,a) + fiboWithDP(n-2,a);
    return a[n];
}



void solve(){
	int n;
	cin >> n;

	vector<int> a(n+1,-1);
	cout << fiboWithDP(n,a) << endl;
}
