class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        int n = ransom.size();
        int m = magazine.size();
        
        sort(ransom.begin(),ransom.end());
        sort(magazine.begin(),magazine.end());
        
        if(n>m){
            return false;
        }
        int k=0;
        for(int i=0; i<m; i++){
            if(ransom[k] == magazine[i] ){
                k++;
                if(k==n){
                    return true;
                }
            }
        }
        
        return false;
    }
};
