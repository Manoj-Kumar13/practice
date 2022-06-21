#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int a,b,c;

	cin >> a >> b >>c;

	int new_a = b - (c-b);
	if(new_a >= a && new_a%a == 0 && new_a!=0){
		cout << "yes";
		return;
	}

	int new_b = a+(c-a)/2;
	if(new_b>=b && (c-a)%2 == 0 && new_b%b == 0 && new_b!=0){
		cout << "yes";
		return;
	}

	int new_c = b + (b-a);
	if(new_c >= c && new_c%c == 0 && new_c!=0){
		cout << "yes";
		return;
	}

	cout << "no";
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
