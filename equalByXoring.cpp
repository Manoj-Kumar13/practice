#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int a,b,n;

	cin >> a >> b >> n;

	if(a == b){
		cout << 0;
		return;
	}

	int comp = a^b;
	int cnt = 0;

	while(comp != 0){
		cnt++;
		comp /= 2;
	}

	if((a^b )< n){
		cout << 1;
		return;
	}

	if(pow(2,cnt-1) >= n){
		cout << -1;
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
