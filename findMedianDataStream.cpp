class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minH;
    priority_queue<int> maxH;
    int sz = 0;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(sz == 0 or maxH.top() >= num){
            maxH.push(num);
            sz++;
        }else{
            minH.push(num);
            sz++;
        }
        
        if(maxH.size() > minH.size() +1){
            minH.push(maxH.top());
            maxH.pop();
        }else if(maxH.size() < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
        
    }
    
    double findMedian() {
        if(sz&1){
            int top = maxH.top();
            return top*1.0;
        }else{
            int top1 = maxH.top();
            int top2 = minH.top();
            
            double med = (top1+top2)/2.0;
            return med;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
