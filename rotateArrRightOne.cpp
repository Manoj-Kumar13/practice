
void rotate(int a[], int n)
{
    int temp = a[0];
    swap(a[0],a[n-1]);
    for(int i=1; i<n; i++){
        int prev = a[i];
        a[i] = temp;
        temp = prev;
    }
}
