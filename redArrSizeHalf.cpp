class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        int n = arr.size();
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        vector<int> a;
        
        for(auto i: m){
            a.push_back(i.second);
        }
        
        sort(a.rbegin(),a.rend());
        int left = 0;
        int ans = 0;
        while(left<n/2){
            left += a[ans];
            ans++;
        }
        
        return ans;
    }
};
