#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n;

	cin >> n;

	if(n%2 == 0){
		cout << 2 << " " << n-3 << " " << 1;
		return;
	}

	if (n%2 == 1)
	{
		int cr = (n-1)/2;
		if (cr%2==0){
		    cout << cr-1 << " " << cr+1  << " " <<1;
	    }else{
	    	cout << cr-2 << " " << cr+2  << " " <<1;
	    }
		return;
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
