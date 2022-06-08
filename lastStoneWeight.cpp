class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        priority_queue<int> q;
        
        for(int i=0;i<stones.size(); i++){
            q.push(stones[i]);
        }
        
        while(!q.empty()){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            
            int nw = x-y;
            if(nw){
                q.push(nw);
            }
            if(q.size() == 1){
                return q.top();
                break;
            }
        }
        
        return 0;
    }
};
