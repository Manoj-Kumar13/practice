#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int
 
void solve(){
	int n,q;
 
	cin >> n >> q;
 
	// cout << n << " " << q;
 
	vector<int> a(n);
 
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
 
	sort(a.begin(),a.end());
	vector<int> s(n+1);
 
	for(int i=0; i<n; i++){
		s[i+1] = s[i]+a[i];
	}
 
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << s[n-x+y] - s[n-x] << endl;
	}
 
}
 
 
 
int32_t main(){
 
	// int t;
	// cin >> t;
	// while(t--){
		solve();
		cout << "\n";
	// }
	
	return 0;
}
