#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int a,b,x,y;

	cin >> a >> x >> b >> y;

	int mn = min(x,y);

	x -= mn;
	y -= mn;

	if(x>=7){
		cout << ">";
		return;
	}else if(y>=7){
		cout << "<";
		return;
	}else{
		for (int i = 0; i < x; ++i)
		{
			a *= 10;
		}
		for (int i = 0; i < y; ++i)
		{
			b *= 10;
		}

		if(a>b){
			cout << ">";
			return;
		}
		if(b>a){
			cout << "<";
			return;
		}else{
			cout << "=";
		}
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
