class Solution {
public:
     bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
          if(s2.size()<s1.size()) return false;
        vector<int> freqS1(26, 0);
        for(char c: s1) freqS1[c-'a']++;
        
        vector<int> freqS2(26, 0);
        int i=0, j=0;
        
        while(j<s2.size()){
            freqS2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freqS1, freqS2)) return true;
            }
            
            if(j-i+1<s1.size()) j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

//another more simpler and faster approach
class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
          if(s2.size()<s1.size()){
              return false;
          }
        
        vector<int> a(26,0);
        vector<int> b(26,0);
        int left = 0, right = 0;
        
        for(int i=0; i<s1.length(); i++){
            a[s1[i]-'a']+=1;
            b[s2[i]-'a']+=1;
            right+=1;
        }
        
        right -=1;        
        
        while(right<s2.length()){
            if(a==b){
                return true;
            }
            right+=1;
            if(right != s2.length()){
                b[s2[right]-'a']+=1;
            }
            b[s2[left]-'a']-=1;
            left+=1;
            
        }
        
        return false;
    }
};
