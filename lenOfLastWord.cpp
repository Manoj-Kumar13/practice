class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int ans = 0;
        bool flag = true;
        
        if(s[n-1] == ' '){
            flag = false;
        }
        
        for(int i=n-1; i>=0; i--){
            if(s[i] == ' ' and flag){
                break;
            }else if(s[i] == ' '){
                continue;
            }
            else{
                ans++;
                flag = true;
            }
        }
        
        return ans;
    }
};
