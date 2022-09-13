#include<bits/stdc++.h>
bool isPossible(vector<int> &rank, int m, int n, int mid){
    
    int dishes = 0;
//     int time = 0;
    for(int i=0; i<n; i++){
        dishes += (-1 + sqrt(1 + (8 * mid) / rank[i])) / 2;
    }
    if(dishes>=m){
        return true;
    }
    return false;
}
int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    sort(rank.begin(),rank.end());
    int n = rank.size();
    int left = 0;
    int right = rank[0]*(m*(m+1)/2);
    int ans  = 0;
    while(left <=right){
        int mid = left + (right-left)/2;
        if(isPossible(rank, m, n, mid)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    
    return ans;
}
