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
void solve(){
	int n;
	cin >> n;

	vector<int> a(n+1,-1);

	cout << minToOne(n,a) << endl;
}
