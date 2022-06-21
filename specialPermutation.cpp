#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n,a,b;

	cin >> n >> a >> b;
	map<int,int> m;

	vector<int> ans;
	ans.push_back(a);
	int maxVal = n;

	for (int i = 1; i < n-1; ++i)
	{
		if(maxVal<1){
			cout << -1;
			return;
		}
		if(maxVal!= a && maxVal != b){
			ans.push_back(maxVal);
			m[maxVal]++;
		}else{
			i--;
		}
		maxVal--;
	}

	ans.push_back(b);

	int minVal = INT_MAX;
	maxVal = INT_MIN;

	for (int i = 0; i < n/2; ++i)
	{
		minVal = min(minVal,ans[i]);
	}

	for (int i = n/2; i < n; ++i)
	{
		maxVal = max(maxVal,ans[i]);
	}

	if(ans.size() == n && minVal == a && maxVal == b){
		for (int i = 0; i < n; ++i)
	    {
		    cout << ans[i] << " ";
	    }
	}else{
		cout << "-1";
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
