class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int ans = -1;
        int n = a.size();
        int left= 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        int target = sum - x;
        sum = 0;
        
        if(target == 0){
            return n;
        }
        
        
        if(target < 0){
            return -1;
        }
        
        for(int i=0; i<n; i++){
            sum +=a[i];
            while(sum> target){
                sum -=a[left++];
            }
            if(sum ==  target){
                ans = max(ans,i-left+1);
            }
        }
        
        return ans == -1 ? -1 : n-ans;
        
    }
};
