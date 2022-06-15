#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int a ,b;

	cin >> a >> b;

	cout << min(a,b);
}


int32_t main(){

	int t;
	cin >> t;
	while(t--){
		solve();
		cout << "\n";
	}
	
	return 0;
}
