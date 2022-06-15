#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	int m = 2;

	while(m<=sqrt(n)){
		if(n%m == 0){
			if(n/m == m){
				cnt++;
			}else{
				cnt +=2;
			}
		}
		m++;
	}

	if(n&1){
		cout << 2*cnt+2;
	}else{
		cout << 2*cnt+1;
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
