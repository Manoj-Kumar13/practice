class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        unordered_map<int,int> m;
        int n = a.size();
        vector<int> ans;
        vector<int> empty;
        if(n&1){
            return ans;
        }
        sort(a.begin(),a.end());
        for(int i=0; i<n; i++){
            m[a[i]]++;
        }
        
        for(int  i=0; i<n; i++){
            if(a[i] == 0){
                if(m[a[i]]%2 == 0 and m[a[i]]>0){
                    m[a[i]] -=2;
                    ans.push_back(a[i]);
                }
            }else if(m[2*a[i]]>0 and m[a[i]] >0){
                m[2*a[i]]--;
                m[a[i]]--;
                ans.push_back(a[i]);
            }
        }
        
        
        if(ans.size() == n/2){
                return ans;
            }
        return empty;
    }
};
