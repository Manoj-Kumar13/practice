class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 and (n&(n-1)) == 0;
    }
};

//recursive approach
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n == 1){
            return true;
        }
        return n>1 and n%2 == 0 and isPowerOfTwo(n/2);
    }
};
