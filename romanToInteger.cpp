class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        int n = s.size();
        
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        if(n <2){
            return m[s[0]];
        }
        
        val = m[s[n-1]];
        for(int i=n-2; i>=0; i--){

            if(m[s[i]] >= m[s[i+1]]){
                val += m[s[i]];
            }else if(m[s[i]] < m[s[i+1]]){
                val -= m[s[i]];
            }
            
        }
        return val;
    }
};
