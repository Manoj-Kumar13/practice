#include<iostream>
#include<bits/stdc++.h>
using namespace std;
        

int main(){

    int n;
    cin >> n;

    int p2 = 0;
    int p1 = 1;

    if(n == 0){
        cout << p2 ;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        int cur = p1+p2;
        p2 = p1;
        p1 = cur;
    }

    cout << p1;
    
    
     
    return 0;
}
