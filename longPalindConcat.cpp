class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        unordered_map<string,int> m;
        int n = a.size();
        
        for(int i=0; i<n; i++){
            m[a[i]] +=2;
        }
        bool flag = false;
        int len = 0;
        for(int i=0; i<n; i++){
            string b = a[i];
            reverse(b.begin(),b.end());
            if(b[0] == b[1]){
                if(m[b] >3){
                    len += 4;
                    m[b] -= 4;
                }else if(m[b] != 0){
                    flag = true;
                }
            }else if(m[b] != 0 and m[a[i]] != 0){
                len += 4;
                m[a[i]] -=2;
                m[b] -=2;
            }
        }
        if(flag){
            len+=2;
        }
        
        return len;
    }
