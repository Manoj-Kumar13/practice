#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n;

	cin >> n;

	string ans = "";

	if(n&1){
		for(int i = 1; i<=n; i++){
			if(i&1){
				ans.push_back('0');
			}else{
				ans.push_back('1');
			}
		}
	}else{
		for(int i = 1; i<=n; i++){
			if(i==1 || i == n){
				ans.push_back('1');
			}else{
				ans.push_back('0');
			}
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
