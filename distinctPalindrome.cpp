#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	int n , x;

	cin >> n >> x;

	if(x>(n+1)/2){
		cout << -1;
		return;
	}

	string ans = "";

	if(n==1){
		cout << "a";
		return;
	}

	vector<char> letters(x);

	for (int i = 0; i < x; ++i)
	{
		letters.push_back(alpha[i]);
		// ans.push_back(alpha[i]);	
	}

	if(n%2 == 0){
		//for even
		for (int i = 0; i < n/2; ++i)
	{
		ans.push_back(alpha[i%x]);
	}

	string helper = string(ans.rbegin(),ans.rend());
	ans = ans + helper;
	}else{
			//for odd
	for (int i = 0; i < n/2; ++i)
	{
		ans.push_back(alpha[i%x]);
	}

	string helper = string(ans.rbegin(),ans.rend());
	ans.push_back(alpha[(n/2)%x]);
	ans = ans + helper;
	}

	
	



	cout << ans;

	
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
