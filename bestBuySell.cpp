class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int diff = 0;
        int lv = a[0];
        
        for(int i=0; i<n; i++){
            if(lv>a[i]){
                lv = a[i]; 
            }
            
            diff = max(diff,a[i]-lv);
        }
        
        return diff;
    }
};
