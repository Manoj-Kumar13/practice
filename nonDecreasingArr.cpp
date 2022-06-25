class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        
        for(int i=0; i<n-1; i++){
            if(a[i]>a[i+1]){
                if(cnt > 1){
                    return false;
                }
             if(i<1 && a[i+1]<a[i]){
                 a[i]=a[i+1];
             }else if(a[i+1]<a[i-1]){
                 a[i+1] = a[i];
             }else{
                 a[i] = a[i-1];
             }
                cnt++;
                i--;
            }
        }
        
        return cnt<=1;
    }
};
