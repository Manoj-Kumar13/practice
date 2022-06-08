class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> q;
        int sol = 0;
        for(int i=0; i<mat.size(); i++){
            int curSol = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    curSol++;
                }
            }
            q.push(make_pair(curSol,i));
             if(q.size()>k){
                q.pop();
            }
        }
        
        vector<int> ans;
        
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
