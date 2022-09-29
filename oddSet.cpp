void solve() {
			int n;
			cin >> n;
 
			vector<int> a(2*n);
			int even = 0, odd =0;
			for(int i=0; i<2*n; i++){
				int x;
				cin >> x;
				a[i] = x;
				if(x&1){
					odd++;
				}else{
					even++;
				}
			}
 
			if(odd == n){
				cout << "yes";
				return;
			}else{
				cout << "no";
				return;
			}
 
			
 
		}
