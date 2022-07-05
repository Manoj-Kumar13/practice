class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s; 
        for(auto i : nums){
            s.insert(i);
        }
        int n = s.size();
        if(n<=2){
            return n;
        }
        vector<int> a;
        
        set<int>:: iterator itr;
        for(itr=s.begin(); itr!=s.end(); itr++){
            a.push_back(*itr);
        }
        n = a.size();
        
        int ans = 0;
        int len = 1;
        
        for(int i=1; i<n; i++){
            if((a[i]-a[i-1]) == 1){
                len++;
            }else{
                ans = max(len,ans);
                len = 1;
            }
        }
        
        return max(len,ans);
    }
};
