class Solution {
public:
    int mySqrt(int x) {
        long ans = x;
        while(ans*ans > x){
            ans = (ans + x/ans)/2;
        }
        return ans;
    }
};

//optimized more approach

int sqrtN(long long int N)
{
    // Write your code here.
     if(N == 0 || N == 1)
    {
        return N;
    }
    long long left = 2;
    long long right = N;
    
    while(left<=right){
        long long mid = left + (right-left)/2;
        
        if(mid <= (N/mid)){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return left-1;
}
