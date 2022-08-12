class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        
        int sum = (n*(n+1))/2;
        
        vector<int> ans;
        int gsum = 0;
        for(int i =0; i<n-1; i++){
            if(a[i] == a[i+1]){
                ans.push_back(a[i]);      
            }
            gsum += a[i];
        }
        
        gsum += a[n-1];
        
        int missing  = ans[0]+(sum-gsum);
        ans.push_back(missing);
        
        return ans;
    }
};
