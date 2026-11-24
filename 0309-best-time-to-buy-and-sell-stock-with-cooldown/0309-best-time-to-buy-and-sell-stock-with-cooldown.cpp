class Solution {
public:
    // int solve(int i , vector<int>& prices,bool b, bool cooldown,vector<vector<vector<int>>> &dp){
    //     if(i == prices.size() ){
    //         return  0;
    //     }
    //     if(dp[i][b][cooldown]!=-1){
    //         return dp[i][b][cooldown];
    //     }
    //     int profit = 0;
    //     if(cooldown){
    //         profit = solve(i+1,prices,b,false,dp);
    //     }
    //     if(!b && !cooldown){
    //         int skip = solve(i+1,prices,b,cooldown,dp);
    //         int buy = solve(i+1,prices,true,cooldown,dp)-prices[i];
    //         profit = max(skip,buy);
    //     }else if(b && !cooldown){
    //         int skip = solve(i+1,prices,b,cooldown,dp);
    //         int sell = solve(i+1,prices,false,true,dp)+prices[i];
    //         profit = max(skip,sell);
    //     }
    //     return dp[i][b][cooldown]=profit;

    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2){
            return 0;
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,0))); 
        // return solve(0,prices,false,false,dp);
        for (int i = n - 1; i >= 0; i--) {
            
            for (int b = 0; b <= 1; b++) {
                dp[i][b][1] = dp[i + 1][b][0];
            }

            
            int skip = dp[i + 1][0][0];
            int buy = dp[i + 1][1][0] - prices[i];
            dp[i][0][0] = max(skip, buy);

            
            int holdSell = dp[i + 1][1][0];
            int sell = dp[i + 1][0][1] + prices[i];
            dp[i][1][0] = max(holdSell, sell);
        }

        return dp[0][0][0];
        
    }
};