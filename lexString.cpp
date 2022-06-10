void solve(){
	string a,b;
	int n,m,k;
 
	cin >> n >> m >>k;
	cin >> a >> b;
 
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
 
	string ans = ""; 
 
	int ac = 0;
	int bc = 0;
 
	while(a.size() !=0 && b.size() != 0){
 
		if(a[0] < b[0] ){
			if(ac < k){
				ans.push_back(a[0]);
			    a = a.substr(1);
			    ac++;
			    bc = 0;
			}else{
				ans.push_back(b[0]);
			    b = b.substr(1);
			    bc++;
			    ac = 0;
			}
			
	}else{
		if(bc < k){
			ans.push_back(b[0]);
			b = b.substr(1);
			bc++;
			ac = 0;
		}else{
			ans.push_back(a[0]);
			a = a.substr(1);
			ac++;
			bc = 0;
		}	
	}
 
	}
 
	cout << ans << endl;
 
}
