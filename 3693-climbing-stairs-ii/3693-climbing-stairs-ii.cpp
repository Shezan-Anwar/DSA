class Solution {
public:
    int helper(int i ,int n, vector<int>& costs,vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int minCost = 1e9;
        if(i+1<=n){
            int one =costs[i] + 1 + helper(i+1,n,costs,dp);
            minCost = min(minCost,one);
        }
        if(i+2<=n){
            int two = costs[i+1] + 4 + helper(i+2,n,costs,dp);
            minCost = min(minCost,two);
        }
        if(i+3<=n){
            int three = costs[i+2] + 9 + helper(i+3,n,costs,dp);
            minCost = min(minCost,three);
        }
        return dp[i] = minCost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n,-1);
        return helper(0,n,costs,dp);
    }
};