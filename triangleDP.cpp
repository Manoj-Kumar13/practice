// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below.
// More formally, if you are on index i on the current row,
// you may move to either index i or index i + 1 on the next row.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> a(triangle.back());
        
        for(int i=n-2; i>=0;i--){
            for(int j=0; j<=i; j++){
                a[j] = min(a[j],a[j+1]) + triangle[i][j];
            }
        }
        
        return a[0];
    }
};
