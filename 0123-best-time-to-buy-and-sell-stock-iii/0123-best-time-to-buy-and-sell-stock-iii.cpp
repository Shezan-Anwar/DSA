class Solution {
public:
    int solve(int k , int i ,bool b, int cp , vector<int>& prices,vector<vector<vector<int>>> &dp){
         if(i == prices.size()){
            return 0;
        }
        if(dp[i][b][k]!=-1){
            return dp[i][b][k];
        }
        if(k==0 && !b){
            return 0;
        }

        int profit = 0;
       
        if(!b){
            int buy = solve(k-1,i+1,true,prices[i],prices,dp) - prices[i];
            int skip = solve(k,i+1,false,INT_MIN,prices,dp);
             profit = max(buy, skip);
            
        }else{
            int sell = solve(k,i+1,false,INT_MIN,prices,dp) + prices[i];
            int hold = solve(k,i + 1, true, cp, prices,dp);
            profit = max(sell,hold);
        }
        return dp[i][b][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(2,0,false,INT_MIN,prices,dp);
    }
};