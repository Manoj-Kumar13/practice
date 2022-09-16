
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        for(long long i=0; i<n; i++){
            minHeap.push(arr[i]);
        }
        
        long long sum = 0;
        
        while(minHeap.size()>1){
            long long ele1 = minHeap.top();
            minHeap.pop();
            long long ele2 = minHeap.top();
            minHeap.pop();
            sum += ele1 + ele2;
            minHeap.push(ele1+ele2);
        }
        
        return sum;
    }
};
