class Solution {
public:
    string makeGood(string s) {
        int n = 0;
        
        while (n != s.length()) {
            n = s.length();
            for (int i = 0; i + 1 < s.size(); ++i)
                if (abs(s[i] - s[i + 1]) == 32){
                    s = s.substr(0, i) + s.substr(i + 2);
                }
    }
    return s;
    }
};
