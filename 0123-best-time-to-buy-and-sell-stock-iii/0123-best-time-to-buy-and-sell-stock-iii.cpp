class Solution {
public:
//***********************MEMOIZATION*******************************************************************
    // int solve(int k , int i ,bool b, int cp , vector<int>& prices,vector<vector<vector<int>>> &dp){
    //      if(i == prices.size()){
    //         return 0;
    //     }
    //     if(dp[i][b][k]!=-1){
    //         return dp[i][b][k];
    //     }
    //     if(k==0 && !b){
    //         return 0;
    //     }

    //     int profit = 0;
       
    //     if(!b){
    //         int buy = solve(k-1,i+1,true,prices[i],prices,dp) - prices[i];
    //         int skip = solve(k,i+1,false,INT_MIN,prices,dp);
    //          profit = max(buy, skip);
            
    //     }else{
    //         int sell = solve(k,i+1,false,INT_MIN,prices,dp) + prices[i];
    //         int hold = solve(k,i + 1, true, cp, prices,dp);
    //         profit = max(sell,hold);
    //     }
    //     return dp[i][b][k]=profit;
    // }
//***************************************************************************************

//_____________________________TABULATION_________________________________________
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i = n-1; i>=0;i--){
            for(int k = 1;k<=2;k++){
                //not holding 
                int buy = dp[i+1][1][k]-prices[i];
                int skip = dp[i+1][0][k];
                dp[i][0][k]=max(buy,skip);

                //holding 
                int sell = dp[i+1][0][k-1]+prices[i];
                int hold = dp[i+1][1][k];
                dp[i][1][k] = max(sell,hold);


            }
        }
        return dp[0][0][2];
        // return solve(2,0,false,INT_MIN,prices,dp);
    }

//__________________________________________________________________________________
};