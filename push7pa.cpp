#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	long long  n;

	cin >> n;

	long long  a[n];

	long long  maxn = 0;
	map<int,int>mapp;
	for (int i = 0; i < n; ++i)
	{
		long long  x;
		cin >> x;
		mapp[x]++;
		a[i] = x;
		
	}
	for(auto i :mapp){
		int c = (i.first + i.second - 1);
		if(maxn < c)
			maxn = c;
	}
	cout<<maxn<<"\n";

}


int main(){

	int t;

	cin >> t;

	while(t--){
		solve();
	}



	return 0;
}