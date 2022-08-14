class Solution {
public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        
        int zp = 0;
        int nzp = 0;
        int zeroes = 0;
        for(int i =0; i<n; i++){
            if(a[i] == 0){
                zeroes++;
            }
        }
        
        while(zp<(n-zeroes)){
            if(a[nzp]!=0 and a[zp] == 0){
                if(nzp>zp){
                  swap(&a[zp],&a[nzp]);   
                    zp++;
                }
                nzp++;
            }else if(a[nzp]==0 and a[zp]!=0){
                nzp++;
                zp++;
            }else if(a[nzp]==0){
                nzp++;
            }else{
                zp++;
            }
        }
    }
};

//snowball approach
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        
        int zs = 0;
        
        for(int i=0; i<n; i++){
            if(a[i] == 0){
                zs++;
            }else if(zs>0){
                int temp = a[i];
                a[i]=0;
                a[i-zs]=temp;
            }
        }
    }
};
