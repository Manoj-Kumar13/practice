#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int a,b;

	cin >> a >> b;

	if(a%10 == 0){
		a = a/10;
	}else{
		a = (a/10)+1;
	}

	if(b%10 == 0){
		b = b/10;
	}else{
		b = (b/10)+1;
	}

	cout << abs(a-b);
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
