class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        for(int i=0; i<n; i++){
            int left = 0, right = m-1;
            
            while(left<=right){
                int mid = (left+right)/2;
                
                if(nums1[i] == nums2[mid]){
                    s.insert(nums1[i]);
                    break;
                }else if(nums1[i]<nums2[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }   
            
        }
        for(auto i: s){
                ans.push_back(i);
            }
            
            return ans;
    }
};
