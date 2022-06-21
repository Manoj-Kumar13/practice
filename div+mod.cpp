void solve2(){
	int l,r,a;
 
	cin >> l >> r >> a;
 
	if(l/a == r/a){
		cout << (r/a) + (r%a);
		return;
	}else{
		cout << max((r/a) + (r%a), ((r)/a-1)+(a-1));
		return;
	}
}
 
 
 
int32_t main(){
 
	int t;
	cin >> t;
	while(t--){
		solve2();
		cout << "\n";
	}
	
	return 0;
}
