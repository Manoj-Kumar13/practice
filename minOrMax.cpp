#include<bits/stdc++.h>
#include <string>
using namespace std;
#define int long long int

// template <typename T>
// class TreeNode
// {
// public:
// 	T data;
// 	vector<TreeNode<T>*> children;
// 	TreeNode(T data){
// 		this->data = data;
// 	}
	
// };

void solve(){
	int n;

	string s;

	cin >> s;

	int ans = 1;

	if(n==2){
		cout << 1 << endl;
		return;
	}

	for (int i = 0; i < n-2; ++i)
	{
		if(s[i] == 1 && s[i+1] == 0){
			ans++;
		}
		if(s[i] == 0 && s[i+1] == 1){
			ans++;
		}
	}

}

void solve2(){
	int n;

    cin >> n;

	int a[n];
	int minn = INT_MAX;
	int maxx = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a[i] = x;
	}

	minn = a[0];
	maxx = a[0];

	for (int i = 0; i < n; ++i)
	{
		if((a[i] <= minn)){
			minn = a[i];
		}else if((a[i] >=maxx)){
			maxx = a[i];
		}else{
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
	return;

}


int32_t main(){

	int t;
	cin >> t;
	while(t--){
		solve2();
	}
	
	return 0;
}
