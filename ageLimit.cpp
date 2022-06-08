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
	int x,y,a;

	cin >> x >> y >> a;

	if(a>=x && a<y){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
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
