#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int
 
void solve(){
	  int n;
        cin >> n;
        map<int, int> q;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++q[x];
        }
        int am = 0;
        for (auto it : q) {
            am = max(am, it.second);
        }
        int ans = 0;
        while(am < n){
        	int d = min(n - am, am);
            ans += 1 + d;
            am += d;
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
