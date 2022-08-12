class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        
        int n = a.length()-1, m = b.length()-1;
        
        while(n >=0 or m>=0 or carry>0){
            if(n>=0){
                carry += a[n] - '0';
                n--;
            }
            if(m>=0){
                carry += b[m] - '0';
                m--;
            }
            
            ans += carry%2 +'0';
            carry /= 2;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
