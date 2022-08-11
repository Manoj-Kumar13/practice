class Solution {
public:
    bool isPalindrome(string s) {
        string ns = "";
        
        for(int i=0; i<s.size(); i++){
            if((s[i] - NULL >=97 and s[i] - NULL <= 122) or (s[i] - NULL >=48 and s[i] - NULL <= 57)){
                ns.push_back(s[i]);
            }else if(s[i] - NULL >=65 and s[i] - NULL <= 90){
                char a = s[i] + 'a'-'A';
                ns.push_back(a);
            }
        }
        
        int n = ns.length();
        
        if(n==0){
            return true;
        }
        int left = 0;
        int right = n-1;
        while(left < right){
            if(ns[left] != ns[right]){
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
