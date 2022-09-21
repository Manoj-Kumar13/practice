class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        vector<int> ans;
        int sum = 0;
        for(int i=0; i<n; i++){
            if(a[i]%2 == 0){
                sum += a[i];
            }
        }
        
        int m = q.size();
        
        for(int i=0; i<m; i++){
            int val = q[i][0];
            int index = q[i][1];
    
                if(a[index] %2 == 0){
                    sum -= a[index];
                }
                a[index] += val;
                
                if(a[index]%2 == 0){
                    sum += a[index];
                }
            ans.push_back(sum);
        }
        
        return ans;
    }
};
