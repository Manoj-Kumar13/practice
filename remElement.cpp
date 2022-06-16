class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int n = a.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i] == val){
                c++;
            }else{
                a[i-c] = a[i];
            }
        }
        
        return n-c;
    }
};
