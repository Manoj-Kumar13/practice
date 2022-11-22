class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n = s.size();
        int m = n+1;
        
        for(int i=0; i<n; i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        
        return t[n];
    }
};

//another approach (using xor)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        char ans = 0;
        for(int i=0; i<n; i++){
            ans = s[i]^t[i]^ans;
        }
        ans = ans^t[n];
        
        return ans;
    }
};

// ques link : https://leetcode.com/problems/find-the-difference/
