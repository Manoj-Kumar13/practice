void subsets(vector<int> &a,int i, int k){
			if(a.size() == 1){
				return;
			}
			int index = (i+k-1)%a.size();
			a.erase(a.begin()+index);
			subsets(a,index,k);
		}

		void solve() {
			vector<int> a(40);

			for(int i=0; i<40; i++){
				a[i] = i+1;
			}

			subsets(a,0,7);

			for(int i=0; i<a.size(); i++){
				if(a[i] !=0 ){
					cout << a[i] << " ";
				}
			}
		}
