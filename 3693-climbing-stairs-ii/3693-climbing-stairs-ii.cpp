class Solution {
public:
    // int helper(int i ,int n, vector<int>& costs,vector<int> &dp){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     int minCost = 1e9;
    //     if(i+1<=n){
    //         int one =costs[i] + 1 + helper(i+1,n,costs,dp);
    //         minCost = min(minCost,one);
    //     }
    //     if(i+2<=n){
    //         int two = costs[i+1] + 4 + helper(i+2,n,costs,dp);
    //         minCost = min(minCost,two);
    //     }
    //     if(i+3<=n){
    //         int three = costs[i+2] + 9 + helper(i+3,n,costs,dp);
    //         minCost = min(minCost,three);
    //     }
    //     return dp[i] = minCost;
    // }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,1e9);
        // return helper(0,n,costs,dp);
        dp[0] = 0; // Cost to be at step 0 is 0

    for (int i = 0; i <= n; i++) {
        if (dp[i] == 1e9) continue; 

        // Jump +1
        if (i + 1 <= n) {
            int cost = costs[i] + 1; // costs[i] corresponds to step i+1 for 1-indexed costs
            dp[i + 1] = min(dp[i + 1], dp[i] + cost);
        }
        // Jump +2
        if (i + 2 <= n) {
            int cost = costs[i + 1] + 4; 
            dp[i + 2] = min(dp[i + 2], dp[i] + cost);
        }
        // Jump +3
        if (i + 3 <= n) {
            int cost = costs[i + 2] + 9;
            dp[i + 3] = min(dp[i + 3], dp[i] + cost);
        }
    }
        

        return dp[n];
    }
};