class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>=3){
            if(n%3 != 0){
                return false;
            }
            n = n/3;
        }
        
        return n==1;
    }
};

//other approach
if(n==0){
            return false;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;

//another approach
return n > 0 == 3**19 % n
