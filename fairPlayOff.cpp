		void solve() {
			// int n;
			// cin >> n;
 
			vector<int> a(4);
			int maxVal1 = INT_MIN;
			int maxVal2 = INT_MIN;
			int minVal1 = INT_MAX;
			int minVal2 = INT_MAX;
 
			for(int i=0; i<2; i++){
				int x;
				cin >> x;
				a[i] = x;
				maxVal1 = max(maxVal1,x);
				minVal1 = min(minVal1,x);
			}
			for(int i=2; i<4; i++){
				int x;
				cin >> x;
				a[i] = x;
				maxVal2 = max(maxVal2,x);
				minVal2 = min(minVal2,x);
			}
 
			if(minVal1 > maxVal2  or minVal2>maxVal1){
				cout << "NO";
			}else{
				cout << "YES";
			}
 
 
 
 
 
 
			
 
		}
