int dp[201][201];
class Solution
{
    public:
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int n) 
    {
        // your code here
        if(n<=1){
            return n;
        }
        
        if(e == 1){
            return n;
        }
        
        if(dp[e][n] != -1){
            return dp[e][n];
        }
        
        int ans = INT_MAX;
        
        for(int i=1; i<=n; i++){
            int temp = 1 + max(eggDrop(e,n-i), eggDrop(e-1,i-1));
            
            ans = min(ans,temp);
        }
        
        return dp[e][n] = ans;
    }
};

//optimised approach (using binary with memoization)
class Solution {
public:
  int find(int e,int n,vector<vector<int>> &memo)
    {   if(n==0||n==1) return n; 
        if(e==1) return n;    
        if(memo[e][n]!=-1) return memo[e][n];
        int ans=1000000,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=find(e-1,mid-1,memo);  
            int right=find(e,n-mid,memo) ; 
            temp=1+max(left,right);        
            if(left<right){              
              l=mid+1;                    
            }
            else                          
            {    
                h=mid-1;
            }
            ans=min(ans,temp);
        }
        
        return memo[e][n]=ans;
     
    }
    int superEggDrop(int e, int n) {

        vector<vector<int>> memo(e+1,vector<int> (n+1,-1));
        return find(e,n,memo);
         
    }
};
