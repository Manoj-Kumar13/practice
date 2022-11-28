class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        unordered_map<int,int> m;
        int n = a.size();
        
        for(int i=0; i<n; i++){
            int first = a[i][0];
            int second = a[i][1];
            
            if(m[first] == 0){
                // do nothing
            }
            m[second]++;
        }
        
        vector<int> zero;
        vector<int> one;
        
        for(auto i: m){
            int first = i.first;
            int second = i.second;
            if(second == 0){
                zero.push_back(first);
            }else if(second == 1){
                one.push_back(first);
            }
        }
        
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());
        
        vector<vector<int>> ans;
        ans.push_back(zero);
        ans.push_back(one);
        return ans;
    }
};

// ques link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
