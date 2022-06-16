class Solution {
public:
    int strStr(string hs, string nd) {
        int n = hs.size();
        int k = nd.size();
        
        if(k==0 || hs == nd){
            return 0;
        }
        string comp = "";
        
        for(int i=0; i<n; i++){
            comp = "";
            if(hs[i] == nd[0]){
                comp.push_back(hs[i]);
                for(int j = 1; j<k; j++){
                    if(hs[i+j] != nd[j]){
                        break;
                    }
                    comp.push_back(hs[i+j]);
                }
                if(comp == nd){
                    return i;
                }
            }
        }
        
        return -1;
    }
};
