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

	cin >> n;

	int a[n];
	int neg = 0;
	int pos = 0;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a[i] = x;
		if(x > 0){
			pos++;
		}else{
			neg++;
		}

	}

	if(pos == neg){
		cout << 0 << endl;
		return;
	}

	if(pos>neg){
		if((pos-neg)&1){
			cout << -1 << endl;
			return;
		}else{
			cout << (pos-neg)/2 << endl;
			return;
		}
	}else{
		if((neg-pos)&1){
			cout << -1 << endl;
			return;
		}else{
			cout << (neg-pos)/2 << endl;
			return;
		}
	}

}




int32_t main(){

	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
