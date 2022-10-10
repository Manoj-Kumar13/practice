class Solution {
public:
    string breakPalindrome(string a) {
        int n = a.length();
        if(n==1){
            return "";
        }
        int odd = false;
        if(n&1){
            odd = true;
        }
        
        for(int i=0; i<n; i++){
            if((a[i] != 'a' and !odd) or (a[i] != 'a' and odd and i != n/2)){
                a[i] = 'a';
                return a;
            }
        }
        
        a[n-1] = 'b';
        return a;
    }
};
