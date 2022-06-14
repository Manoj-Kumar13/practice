class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int reslen = 0;
        int l = 0, r = 0;
        
        for(int i=0; i<n; i++){
            // odd length
            l = i;
            r = i;
            while(l>=0 and r<n and (s[l] == s[r])){
                if((r-l+1)>reslen){
                    reslen = r-l+1;
                    res = s.substr(l,reslen);
                }
                l--;
                r++;
            }
            
            // even length
            l = i;
            r = i+1;
            while(l>=0 and r<n and (s[l] == s[r])){
                if((r-l+1)>reslen){
                    reslen = r-l+1;
                    res = s.substr(l,reslen);
                }
                l--;
                r++;
            }
            
        }
        
        return res;

    }
};
