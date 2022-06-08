class Solution {
public:
    
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> q;
        for(int i = 0; i<score.size(); i++){
            q.push(make_pair(score[i],i));
        }
        
        vector<string> output(score.size());
        string fr[] = {"Gold Medal","Silver Medal","Bronze Medal"};
        int cnt = 0;
        while(!q.empty()){
            if(cnt<3){
                output[q.top().second] = fr[cnt];
                cnt++;
                q.pop();
            }else{
                cnt++;
                output[q.top().second] = to_string(cnt);
                q.pop();
            }
        }
        return output;
    }
};
