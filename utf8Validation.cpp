class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rem = 0;
        
        for(auto i : data){
            if(rem == 0){
                if((i>>7) == 0b0){
                    rem = 0;
                }else if((i>>5) == 0b110){
                    rem = 1;
                }else if((i>>4) == 0b1110){
                    rem = 2;
                }else if((i>>3) == 0b11110){
                    rem = 3;
                }else{
                    return false;
                }
            }else{
                if((i>>6) == 0b10){
                    rem--;
                }else{
                    return false;
                }
            }
        }
        
        if(rem == 0){
            return true;
        }

        return false;
    }
};
