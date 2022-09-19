void subsets(int n, int ones, int zeros, string output){
			if(output.size() == n){
				cout << output << endl;
				return;
			}

			string op1 = output + "1";
			subsets(n , ones+1, zeros, op1);

			if(ones > zeros){
				string op2 = output + "0";
				subsets(n,ones, zeros+1,op2);
			}

		}

		void solve() {
			int n;
			cin >> n;

			subsets(n,1,0, "1");
		}
