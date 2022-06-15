class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int n = strs.size();
        string ans = "";
        
        for(int i = 1; i<n; i++){
            ans = "";
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j] == res[j]){
                    ans.push_back(strs[i][j]);
                }else{
                    break;
                }
            }
            res = ans;
        }
        
        return res;
    }
};
