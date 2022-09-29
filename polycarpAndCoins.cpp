	void solve() {
			int n;
			cin >> n;
 
			if(n%3 == 0){
				cout << n/3 << " " << n/3;
				return;
 
			}else if(n%3 == 1){
				cout << n/3+1 << " " << n/3;
				return;
			}else{
				cout << n/3 << " " << n/3+1;
				return;
			}
 
			
 
		}
 
