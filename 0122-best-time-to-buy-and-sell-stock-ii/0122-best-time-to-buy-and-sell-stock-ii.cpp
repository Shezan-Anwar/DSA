class Solution {
public:
    int solve(int i, bool b, int cp, vector<int>& prices, vector<vector<int>>& dp){

        if(i==prices.size()){
            return 0;
        }
        if(dp[i][b]!=-1){
            return dp[i][b];
        }

        int profit = 0;
        if (!b) {
            int buy = solve(i + 1, true, prices[i], prices, dp) - prices[i];
            int skip = solve(i + 1, false, INT_MIN, prices, dp);
            profit = max(buy, skip);
        }else {
            
            int sell = solve(i + 1, false, INT_MIN, prices, dp) + prices[i];
            int hold = solve(i + 1, true, cp, prices, dp);
            profit = max(sell, hold);
        }
        
        return dp[i][b]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0, false, INT_MIN,prices,dp);
        // int max_profit = 0;
        
        // for (size_t i = 1; i < prices.size(); ++i) {
        //     if (prices[i] > prices[i - 1]) {
        //         max_profit += (prices[i] - prices[i - 1]);
        //     }
        // }
        
        // return max_profit;
    }
};