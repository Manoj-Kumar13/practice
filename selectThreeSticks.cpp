void solve() {
			int n;
			cin >> n;
 
			vector<int> a(n);
			map<int,int> m;
			int mf = 0;
 
			for(int i=0; i<n; i++){
				cin >> a[i];
				m[a[i]]++;
				mf = max(mf,m[a[i]]);
			}
			sort(a.begin(),a.end());
 
			if(mf>=3){
				cout << 0;
				return;
			}
			int minD = INT_MAX;
			for(int i=0; i<n-2; i++){
				int d1 = abs(a[i] - a[i+1]);
				int d2 = abs(a[i+1] - a[i+2]);
				minD = min(minD, d1+d2);
			}
 
			cout << minD;
 
		}
