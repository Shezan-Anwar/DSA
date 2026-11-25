class Solution {
public:
    int solve(int i,vector<int>& prices,int fee,bool b,vector<vector<int>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][b]!=-1){
            return dp[i][b];
        }

        int profit = 0;
        if(!b){
            int buy = solve(i+1,prices,fee,true,dp)-prices[i]-fee;
            int skip = solve(i+1,prices,fee,false,dp);
            profit = max(skip,buy);
        }else{
            int sell = solve(i+1,prices,fee,false,dp)+prices[i];
            int skip = solve(i+1,prices,fee,true,dp);
            profit = max(skip,sell);
        }
        return dp[i][b]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<2){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,fee,false,dp);
    }
};