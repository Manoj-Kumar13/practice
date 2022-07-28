class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        
        int s1 = s.size();
        int s2 = t.size();
        if(s1 != s2){
            return false;
        }
        
        for(int i =0; i< s1; i++){
            m[s[i]]++;
        }
        
        for(int i=0; i<s2; i++){
            if(m[t[i]] == 0){
                return false;
            }
            m[t[i]]--;
        }
        
        return true;
    }
};
