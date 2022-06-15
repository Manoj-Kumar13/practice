#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

// 00 is replaced with A
// 01 is replaced with T
// 10 is replaced with C
// 11 is replaced with G

void solve(){
	string s;
	int n;

	cin >> n;
	cin >> s;

	string ans = "";

	for(int i=0; i<n; i+=2){
		if(s[i] == '0' && s[i+1] == '0' ){
			ans.push_back('A');
		}else if(s[i] == '0' && s[i+1] == '1' ){
			ans.push_back('T');
		}else if(s[i] == '1' && s[i+1] == '0' ){
			ans.push_back('C');
		}else{
			ans.push_back('G');
		}
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
