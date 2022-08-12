class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int k) {
        
        int n = a.size();
        
        if(k==0){
            return true;
        }
        
        if(n<3){
            if(k>1){
                return false;
            }
            
                if(a[0] == 0){
                    return true;
                }else{
                    return false;
                }
            
        }
        
        if(a[0] == 0 and a[1] == 0){
            a[0] = 1;
            k = k-1;
        }
        
        for(int i=1; i<n-1; i++){
            if(a[i-1] == 0 and a[i+1] == 0){
                if(a[i] == 0){
                    a[i] =1;
                    k = k-1;
                }
            }
        }
        
        
        if(a[n-1] == 0 and a[n-2] == 0){
            a[n-1] = 1;
            k = k-1;
        }
        
        if(k>0){
            return false;
        }
        return true;
    }
};


// short and clean code
 flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; ++i)
        {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
            {
                --n;
                ++i;
            }
                
        }
        return n <=0;
