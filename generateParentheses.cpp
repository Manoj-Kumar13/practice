class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,"",n,0);
        return ans;
    }
    
    void helper(vector<string>& ans, string s, int n,int m){
        if(n==0 && m==0){
            ans.push_back(s);
            return;
        }
        
        if(n>0){
            helper(ans,s + "(",n-1,m+1);
        }
        if(m>0){
            helper(ans,s + ")",n,m-1);
        }
    }
};


//another approach(clean code)
void generateParenthesis(int opn, int cls, string output){
			if(cls == 0){
				cout << output << endl;
				return;
			}

			if(opn){
				string op1 = output + "(";
				subsets(opn-1,cls,op1);
			}
			if(cls-opn){
				string op2 = output + ")";
				subsets(opn,cls-1,op2);
			}

		}

		void solve() {
			int n;
			cin >> n;

			subsets(n,n, "");
		}
