class Solution {
public:
    vector<string> findRestaurant(vector<string>& a, vector<string>& b) {
        
        vector<string> ans;
        map<string,int> m;
        int n = a.size();
        int p = b.size();
        
        for(int i=0; i<n; i++){
            m[a[i]] = i+1;
        }
        int count = INT_MAX;
        for(int i=0; i<p; i++){
            if(m[b[i]]>0 and m[b[i]]+i-1 <count){
                count = m[b[i]] + i-1;
                ans.clear();
                ans.push_back(b[i]);
            }else if(m[b[i]]>0 and m[b[i]]+i-1 == count){
                ans.push_back(b[i]);
            }
        }
        
        return ans;
    }
};
