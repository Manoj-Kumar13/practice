#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n , k;

	cin >> n >> k;

	if(n==k || n<=5){
		cout << 0;
		return;
	}

	int ans= 0;

	for (int i = k; i <= n; i++)
	{
		if(i%5 == 0 && i !=n){
			ans++;
		}
	}

	cout << ans;
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
