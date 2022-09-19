	void toh(int n, int s, int d, int h){
			if(n==1){
				cout<< "moving plate " << n <<  " from " << s << " to " << d << endl;
				return;
			}

			toh(n-1, s, h, d);
			cout << "moving plate " << n <<  " from " << s << " to " << d << endl;
			toh(n-1, h, d, s);
		}

		void solve() {
			int n;
			cin >> n;
			int count = 0, s =1, d = 3, h =2;


			toh(n,s,d,h);
		}
