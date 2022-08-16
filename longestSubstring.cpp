class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        
        int left= 0, right = 0;
        int n = s.size();
        int len = 0;
        
        while(right<n){
            if(mpp[s[right]] != -1){
                left = max(left,mpp[s[right]]+1);
            }
            
            mpp[s[right]] = right;
            len = max(len,right-left +1);
            right++;
        }
        return len;
    }
};


// alternate: more readable approach

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> ss;
        
        int left = 0;
        int n = s.length();
        int len = 0;
        
        for(int i=0; i<n; i++){
            while(ss.find(s[i]) != ss.end()){
                ss.erase(s[left]);
                left = left+1;
            }
            ss.insert(s[i]);
            len = max(len,i-left+1);
        }
        
        return len;
    }
};
