#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n,m;

	cin >> n >> m;

	if(n==1 and m==1){
		cout << 0;
	}else if(min(n,m) == 1){
		cout << 1;
	}else{
		cout << 2;
	}
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
