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


// python implementation
// dp = []
// class Solution:
//     def tribonacci(self, n: int) -> int:
//         if n == 0:
//             return 0
//         elif n==1 or n==2:
//             return 1
        
//         a=0
//         b=1
//         c=1
        
//         for i in range(3,n+1):
//             temp = a+b+c
//             a=b
//             b=c
//             c=temp
//         return c
