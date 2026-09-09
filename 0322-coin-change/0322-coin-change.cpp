class Solution {
public:
    int helper(vector<int>& coins, int rem,vector<int>& dp){
        if(rem < 0 ){
            return -1;
        }
        if(rem == 0){
            return 0 ;
        }
        if(dp[rem]!=-2){
            return dp[rem];
        }

        int minCoin = INT_MAX;

        for(int coin : coins){
            int res = helper(coins, rem-coin,dp);
            if(res>=0 && res < minCoin){
                minCoin = res+1;
            }
        }
        dp[rem]=minCoin==INT_MAX? -1 : minCoin;
        return dp[rem];
    }
    int coinChange(vector<int>& coins, int amount) {
        // if(amount == 0){
        //     return 0;
        // }
        // vector<int> dp(amount+1, amount+1);

        // dp[0]=0;
        // for(int i = 1 ; i <= amount ; i++){
        //     for(int coin : coins){
        //         if(i-coin>=0){
        //             dp[i]=min(dp[i],dp[i-coin]+1);
        //         }
        //     }
        // }
        // return dp[amount]>amount ? -1 : dp[amount];
        if(amount == 0)return 0;
        vector<int> dp(amount + 1,-2);
        return helper(coins, amount , dp);
    }
};