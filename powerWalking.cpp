#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

void solve(){
	int n;
    cin >> n;

    map<int,int> m;
    vector<int> a;

    for (int i = 0; i < n; ++i)
    {
    	int x;
    	cin >> x;
    	a.push_back(x);
    	m[x]++;
    }

    int ms = m.size();

    for (int i = 1; i <=n; ++i)
    {
    	if(i<=ms){
    		cout << ms << " ";
    	}else{
    		cout << i << " ";
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
