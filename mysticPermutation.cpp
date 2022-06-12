void solve(){
   int n;
   cin>>n;
   int arr[n];
   for (int i = 0; i < n; ++i)
   {
    cin>>arr[i];
    }
    if(n == 1){
        cout<<-1;return;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for (int i = 1; i <= n; ++i)
    {
        pq.push(i);
    }
    vector<int>v;
    bool ans = false;
    for(int i = 0; i < n ;i++){
        if(arr[i] == pq.top() && pq.size()>=2){
            int a = pq.top();
            pq.pop();
            v.push_back(pq.top());
            pq.pop();
            pq.push(a);
        }
        else if(arr[i] == pq.top() && pq.size() == 1){
            ans = true;
              v.push_back(pq.top());
        }
        else{
              v.push_back(pq.top());
            pq.pop();
        }
    }
    if(ans)
    swap(v[v.size()-1],v[v.size()-2]);
    for(auto i :v){
        cout<<i<<" ";
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
