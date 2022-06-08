class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q1;
        
        for(int i=0; i<nums.size(); i++){
            q1.push(make_pair(nums[i],i));
        }
        vector<int> ans;
        vector<int> helper;
        
        for(int i=0; i<k; i++){
            helper.push_back(q1.top().second);
            q1.pop();
        }
        sort(helper.begin(),helper.end());
        for(int i=0; i<k; i++){
            ans.push_back(nums[helper[i]]);
        }
        
        
        return ans;
    }
};
