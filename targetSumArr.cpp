typedef long ll;
class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<ll> pq(t.begin(), t.end());
        // int n = t.size();
        ll sum = 0;
        
        for(ll el : t){
            sum += el;
        }
        
        while(true){
            ll ttop = pq.top();
            pq.pop();
            sum -= ttop;
            if(sum == 1 || ttop == 1){
                return true;
            }
            if(ttop < sum || sum == 0|| ttop % sum == 0){
                return false;
            }
            
            ttop = ttop%sum;
            pq.push(ttop);
            sum += ttop;
        }
        
    }
};
