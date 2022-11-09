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

//another appraoch
class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty() or s.top().first > price){
            s.push({price,1});
            return 1;
        }
        
        int span = 1;
        
        while(!s.empty()){
            if(s.top().first <= price){
                span += s.top().second;
                s.pop();
            }else{
                break;
            }
        }
        s.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// link: https://leetcode.com/problems/online-stock-span/
