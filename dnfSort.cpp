int left =0;
    int right = n-1;
    
    int mid = 0;
    
    while(mid<right){
        if(a[mid] == 0){
            swap(a[mid], a[left]);
            // mid++;
            left++;
        }else if(a[mid] == 2){
            swap(a[mid], a[right]);
            // mid++;
            right--;
        }
        mid++;
    }
