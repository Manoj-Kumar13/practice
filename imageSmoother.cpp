class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size(), col = img[0].size();
        vector<vector<int>> ans(row,vector<int>(col));

        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) {
                int count = 0;
                for (int nr = r-1; nr <= r+1; ++nr)
                    for (int nc = c-1; nc <= c+1; ++nc) {
                        if (0 <= nr && nr < row && 0 <= nc && nc < col) {
                            ans[r][c] += img[nr][nc];
                            count++;
                        }
                    }
                ans[r][c] /= count;
            }
        return ans;
    }
};
