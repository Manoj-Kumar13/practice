class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        int slow = 0;
        slow = a[slow];
        int fast = 0;
        fast = a[a[fast]];
        
        while(fast!=slow){
            slow = a[slow];
            fast = a[a[fast]];
        }
        
        fast = 0;
        
        while(fast!=slow){
            slow = a[slow];
            fast = a[fast];
        }
        
        return slow;
    }
};
