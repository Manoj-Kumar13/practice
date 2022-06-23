class Solution {
public:
    int scheduleCourse(vector<vector<int>>& v) {
        priority_queue<int> pq;
        sort(v.begin(),v.end(),[](auto &a, auto &b) {return a[1] < b[1];});
        int total = 0;
        for(auto &course: v){
            int dur = course[0], end = course[1];
            if(dur+total<=end){
                total += dur;
                pq.push(dur);
            }else if(pq.size() && pq.top()>dur){
                total += dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        
        return pq.size();
    }
};
