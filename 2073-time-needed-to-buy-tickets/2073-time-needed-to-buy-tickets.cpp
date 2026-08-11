class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0 ;    
       int target = tickets[k];
        
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                ans += min(tickets[i], target);
            } else {
                ans += min(tickets[i], target - 1);
            }
        }
        return ans;
    }
};