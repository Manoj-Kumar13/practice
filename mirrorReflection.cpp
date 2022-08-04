class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ref = p, ext = q;
        
        while(ref%2 == 0 && ext%2 == 0){
            ext = ext/2;
            ref = ref/2;
        }
        
        if(ref%2 == 0){
            return 2;
        }else if(ext %2 ==  1 && ref%2 == 1 ){
            return 1;
        }else{
            return 0;
        }
    }
};
