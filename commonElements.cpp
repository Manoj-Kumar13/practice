class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            unordered_map<int,int> m;
            unordered_set<int> s1;
            unordered_set<int> s2;
            unordered_set<int> s3;
            
            for(int i=0; i<n1; i++){
                s1.insert(a[i]);
            }
            for(int i=0; i<n2; i++){
                s2.insert(b[i]);
            }
            for(int i=0; i<n3; i++){
                s3.insert(c[i]);
            }
            
            for(auto i: s1){
                m[i]++;
            }
            for(auto i: s2){
                m[i]++;
            }
            for(auto i: s3){
                m[i]++;
            }

            
            
            vector<int> ans;
            for(auto i: m){
                if(i.second == 3){
                    ans.push_back(i.first);
                }
            }
            sort(ans.begin(),ans.end());
            
            return ans;
        }

};
