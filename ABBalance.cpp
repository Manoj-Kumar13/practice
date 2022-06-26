void solve(){
	string s;
	cin >> s;

	int n = s.size();

	if(s[0] == s[n-1]){
		cout << s;
		return;
	}else{
		cout << s[n-1]+s.substr(1);
		return;
	}


}
 
int32_t main()
 {
   cin.tie(NULL);
    int t;
    t = 1;
    scanf("%d",&t);
    while(t--){
        solve();
        cout<<"\n";
    }
}
