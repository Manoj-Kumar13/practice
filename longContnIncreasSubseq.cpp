class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n = a.size();
        int len = 1;
        for(int i=0; i<n-1; i++){
            int clen = 1;
            while(i<n-1 and a[i] < a[i+1]){
                clen++;
                i++;
            }
            len = max(clen,len);
        }
        
        return len;
    }
};
