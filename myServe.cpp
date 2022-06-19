#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int a,b;

	cin >>  a >> b;

	int x = a+b;

	 if((x+1)%4 == 0 || (x%2 == 0 && x%4 != 0)){
		cout << "BOB";
	}else{
		cout << "ALICE";
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
