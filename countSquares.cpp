 long long left = 0,right = N;
        long long ans = 0;
        
        while(left<=right){
            long long mid = left + (right-left)/2;
            
            if(mid*mid == N){
                ans = mid;
                break;
            }
            
            if(mid*mid < N){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        // int cnt = 0;
        
        if(ans*ans == N){
            return ans-1;
        }
        
        return ans;
