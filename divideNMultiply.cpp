#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n;
	cin >> n;
	int a[n];

	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	int sum = 0;
	int temp = 1;

	for(int i=0; i<n; i++){
		while(a[i]%2 == 0){
			a[i] /= 2;
			temp *= 2;
		}
	}

	sort(a,a+n);	
	a[n-1] *= temp;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}

	cout << sum;


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
