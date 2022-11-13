class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int a[], int n)
    {
        //Your code here
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += a[i];
            if(m[sum]!=0){
                return true;
            }
            m[sum]++;
        }
        return false;
    }
};
