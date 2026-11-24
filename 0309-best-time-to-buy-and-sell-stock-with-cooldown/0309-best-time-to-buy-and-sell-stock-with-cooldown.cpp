class Solution {
public:
    int solve(int i , vector<int>& prices,bool b, bool cooldown,vector<vector<vector<int>>> &dp){
        if(i == prices.size() ){
            return  0;
        }
        if(dp[i][b][cooldown]!=-1){
            return dp[i][b][cooldown];
        }
        int profit = 0;
        if(cooldown){
            profit = solve(i+1,prices,b,false,dp);
        }
        if(!b && !cooldown){
            int skip = solve(i+1,prices,b,cooldown,dp);
            int buy = solve(i+1,prices,true,cooldown,dp)-prices[i];
            profit = max(skip,buy);
        }else if(b && !cooldown){
            int skip = solve(i+1,prices,b,cooldown,dp);
            int sell = solve(i+1,prices,false,true,dp)+prices[i];
            profit = max(skip,sell);
        }
        return dp[i][b][cooldown]=profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2){
            return 0;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1))); 
        return solve(0,prices,false,false,dp);
        
    }
};