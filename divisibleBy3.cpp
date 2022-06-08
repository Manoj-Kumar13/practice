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
	int a,b;

	cin >> a >> b;


	if(a%3 == 0 || b%3 == 0){
		cout << 0 << endl;
		return;
	}


	if((a%3 == 1 && b%3 == 1) || (a%3 == 2 && b%3 == 2)){
		cout << 1 << endl;
		return;
	}else{

		cout << 2 << endl;
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
