class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=-1;
        
        long long int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum%k;
            
            if(m.find(rem) == m.end()){
                m[rem] = i;
            }else if(i-m[rem] > 1){
                return true;
            }
        }
        
        return false;
    }
};
