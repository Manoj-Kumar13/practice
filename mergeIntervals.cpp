class Solution {
public:
//     bool cmp(vector<int> a, vector<int> b)
//     {
//         return (a[0] > b[0]);
//     }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){return a[0] < b[0];});
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        
        ans.push_back(temp);
        int j = 0;
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans[j][1]){
                if(intervals[i][1] > ans[j][1]){
                    ans[j][1] = intervals[i][1];
                }
                
            }else{
                j++;
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};

// ques link : https://leetcode.com/problems/merge-intervals/
