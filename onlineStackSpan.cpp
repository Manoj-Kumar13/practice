class StockSpanner {
public:
    vector<int> a;
    int n = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        if(n == 0){
            a.push_back(price);
            n++;
            return 1;
        }
        
        if(price < a[n-1]){
            a.push_back(price);
            n++;
            return 1;
        }
        int i = n;
        while(i > 0 and a[i-1] <= price){
            ans++;
            i--;
        }
        a.push_back(price);
        n++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// link: https://leetcode.com/problems/online-stock-span/
