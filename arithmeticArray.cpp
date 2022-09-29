void solve() {
			int n;
			cin >> n;
 
			vector<int> a(n);
			int sum = 0;
 
			for (int i = 0; i < n; ++i)
			{
				int x;
				cin >> x;
				a[i] = x;
				sum += x;
			}
 
			if(sum/n <1){
				cout << 1;
				return;
			}
 
			cout << sum - n;
 
			
 
		}
