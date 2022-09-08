class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        vector<string> ans;
        
        string temp = "";
        
        for(int i = 0; i < n; i++)
        {
            int j = i;
            while(j + 1 < n && a[j + 1] == a[j] + 1){
                j++;
            }

            if(j > i){
                temp += to_string(a[i]);
                temp += "->";
                temp += to_string(a[j]);
            }else{
                temp += to_string(a[i]);
            }
            
            ans.push_back(temp);
            temp = "";
            i = j;
        }
        
        return ans;
    }
};
