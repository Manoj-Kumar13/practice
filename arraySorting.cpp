	#include<bits/stdc++.h>
	using namespace std; 
	typedef long long int ll; 
	ll Mod = 1000000007;
	bool prime[1000];
	vector<int>Graph[300004];
	vector<ll>primes;

	/*****************************************************/
	void sieve(ll n)
	{
	    memset(prime, true, sizeof(prime));
	 
	    for (ll p = 2; p * p <= n; p++)
	    {
	        if (prime[p] == true) 
	        {
	            for (ll i = p * p; i <= n; i += p)
	                prime[i] = false;
	        }
	    }
	 
	    for (ll p = 2; p <= n; p++)
	        if (prime[p])
	        primes.push_back(p); 
	}
	/*****************************************************/
	ll power(ll x,  ll y){
	    if (y == 0)
	        return 1;
	    else if (y % 2 == 0)
	        return ((power(x, y / 2)) * (power(x, y / 2)));
	    else
	        return ((((x  ) * ((power(x, y / 2)))) * (power(x, y / 2))));
	}    
	/*****************************************************/
	ll powermod(ll x,  ll y, ll Mod){
	    if (y == 0)
	        return 1;
	    else if (y % 2 == 0)
	        return ((powermod(x, y / 2,Mod)%Mod) * (powermod(x, y / 2,Mod)%Mod))%Mod;
	    else
	        return ((((x  %Mod) * ((powermod(x, y / 2,Mod)%Mod)))%Mod * (powermod(x, y / 2,Mod)%Mod))%Mod)%Mod;
	}
	/*****************************************************/
	bool sortbysecdesc(const  pair<ll,ll> &a,
	                   const pair<ll,ll> &b)
	{
	       return a.second < b.second;
	 
	}
	/*****************************************************/
	bool isprime(ll n){
	    if(n==1)
	        return false;
	    if(n==2 || n==3)
	        return true;
	    if(n%2==0 || n%3==0)
	        return false;
	    for(ll i=5; i*i<=n; i=i+6){
	        if(n % i == 0 || n % (i + 2) == 0)
	            return false; 
	    }
	    return true;
	}
	/*****************************************************/
	template <class T> void _print( T x){ cerr<<x; }
	template <class T, class V> void _print(pair <T, V> p);
	template <class T> void _print(vector <T> v);
	template <class T> void _print(set <T> v);
	template <class T, class V> void _print(map <T, V> v);
	template <class T> void _print(multiset <T> v);
	template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
	template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
	template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
	template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
	template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
	template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
	template <class T> void _print( T arr[] ,int n){ cerr<<"[ "; for(int i=0; i<n; i++) { cerr<<arr[i]<<" ";} cerr<<"]";}
	/*****************************************************/

	void solve2(){
		ll n;
		cin >> n;

		vector<int> a(n);
		map<int,int> m;

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}


		vector<vector<int>> dp(n+1,vector<int>(n+1));

		// for (int i = 0; i < n+1; ++i)
		// {
		// 	// if(i==0){
		// 	// 	dp[i][0] = a[i];
		// 	// }
		// 	for (int j = 0; j < n+1; ++i)
		// 	{
		// 		// if(j==0){
		// 		// 	dp[0][j] =a[j];
		// 		// }
		// 		dp[i][j] = max((dp[i-1][j-1] *a[i]),dp[i-1][j-1]*(1000-a[i]));
		// 	}
		// }

		cout << dp[n][n];
	}


	void solve(){
	ll n;
    cin>>n;

    vector<ll> a(n+1);
     map<ll,ll>m;
     vector<ll> v;

    for (ll i=1; i<=n; i++)
    {
       cin>>a[i];
       m[a[i]] = i ;
    }

    for (ll i=1; i<=n; i++)
    {
        if(a[i] == i )
            continue;

        v.push_back(m[i] - i);
        ll cnt = m[a[i]];
        swap(a[cnt],a[i]);
        m[i] = cnt;
    }
    ll ans = 0;
    for(auto i:v){
        ans = __gcd(ans,i);
    }

    cout << abs(ans);

	}
	 
	int32_t main()
	 {
	   cin.tie(NULL);
	    int t;
	    t = 1;
	    scanf("%d",&t);
	    while(t--){
	        solve();
	        cout<<"\n";
	    }
	}
