class Solution {
public:
    long long MOD = 1e9 + 7;
    // int solve(int n,vector<long long> &dp){
    //     if(n<=1){
    //         return 1;
    //     }
        
    //     if(n==2){
    //         return 2;
    //     }
    //     if(n==3){
    //         return 5;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n]=(2LL * solve(n-1,dp) + solve(n-3,dp)) % MOD;

    // }
    int numTilings(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        vector<long long> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        // return solve(n,dp);
        for (int i = 4; i <= n; ++i) {
            dp[i] = (2LL * dp[i - 1] + dp[i - 3]) % MOD;
        }
        return int(dp[n]);
    }
};