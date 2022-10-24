class Solution {
public:
    bool compare(string a, vector<bool>& selected){
        vector<bool> selfCheck(25,false);
        
        for(int i=0; i<a.size(); i++){
            if(selfCheck[a[i] - 'a'] == true){
                return false;
            }else{
                selfCheck[a[i] - 'a'] = true;
            }
        }
        
        for(int i=0; i<a.size(); i++){
            if(selected[a[i] - 'a'] == true){
                return false;
            }
        }
        
        return true;
        
    }
    
    int helper(int i, vector<string>& a, vector<bool>& selected, int len){
        if(i == a.size()){
            return len;
        }
        
        if(compare(a[i], selected) == false){
            return helper(i+1, a, selected, len);
        }else{
            //pick
            for(int j=0; j<a[i].size(); j++){
                selected[a[i][j] - 'a'] = true;
            }
            len += a[i].length();
            int op1 = helper(i+1, a, selected, len);
            
            //not pick
            for(int j=0; j<a[i].size(); j++){
                selected[a[i][j] - 'a'] = false;
            }
            len -= a[i].length();
            int op2 = helper(i+1, a, selected, len);
            
            return max(op1,op2);
        }
    }
    int maxLength(vector<string>& a) {
        vector<bool> selected(26,false);
        return helper(0,a,selected,0);
    }
};
