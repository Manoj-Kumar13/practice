class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        for(int i=0; i<n; i++){
            int m = nums2.size();
            int left = 0, right = m-1;

            while(left<=right){
                int mid = (left+right)/2;

                if(nums1[i] == nums2[mid]){
                    ans.push_back(nums1[i]);
                    nums2.erase(nums2.begin()+mid);
                    break;
                }else if(nums1[i]<nums2[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }   

        }

            return ans;
    }
};
