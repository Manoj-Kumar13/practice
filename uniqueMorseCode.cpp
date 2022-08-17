class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mc = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        
        unordered_set<string> s;
        for (auto w : words) {
            string code;
            for (auto c : w){
                code += mc[c - 'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};
