class Solution {
public:
// bool compareInterval(const pair<int,string> &i1, const pair<int,string> &i2)
// {
//     if(i1.first == i2.first){
//         return i1.second  < i2.second;
//     }
//     return i1.first > i2.first;
// }
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>>pq;
        map<string,int>mapp;
        for(auto i : words){
            mapp[i]++;
        }
        for(auto i :mapp){
            pq.push({i.second,i.first});
        }
        vector<pair<int,string>>v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        sort(v.begin(),v.end(),[&](const pair<int,string> &i1, const pair<int,string> &i2)
{
    if(i1.first == i2.first){
        return i1.second  < i2.second;
    }
    return i1.first > i2.first;
});
        // for(auto i : v){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        vector<string>ans;
             for(auto i : v){
                 k--;
                 ans.push_back(i.second);
                 if(k == 0)
                 break;
            // cout<<i.first<<" "<<i.second<<"\n";
        }
        return ans;
    
   }
};
