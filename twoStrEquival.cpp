class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
        string str1 = "", str2 = "";
        
        for(int i=0; i<a.size(); i++){
            str1 += a[i];
        }
        
        for(int i=0; i<b.size(); i++){
            str2 += b[i];
        }
        
        return str1 == str2;
    }
};
