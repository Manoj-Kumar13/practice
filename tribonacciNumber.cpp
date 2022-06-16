class Solution {
public:
    int tribonacci(int n) {
        int t1 = 0;
        int t2 = 1;
        int t3 = 1;
        
        if(n <=1){
            return n;
        }
        if(n == 2){
            return 1;
        }
        
        for(int i =3; i<=n; i++ ){
            int cur = t1+t2+t3;
            t1 = t2;
            t2 = t3;
            t3 = cur;
        }
        
        return t3;
    }
};
