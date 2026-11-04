class Solution {
public:
    vector<int> perfectSq(int n){
        int i = 1;
        vector<int> ps;
        while(i*i<=n){
            ps.push_back(i*i);
            i++;
        }
        return ps;
    }
//---------------memoization-------------------------------
    // int solve(int n,int count, vector<int> &ps,vector<int> &dp){
    //     if(n==0){
    //         return 0;
    //     }
        
    //     if(n<0){
    //         return INT_MAX;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int minCount = INT_MAX;
    //     for(int p : ps){
    //         if(p <= n) {
    //             int res = solve(n - p, count + 1, ps,dp);
    //             if(res != INT_MAX) {
    //                 minCount = min(minCount, 1 + res);
    //             }
    //         }
    //     }
    //     return dp[n] = minCount;

    // }

//---------------------------------------------------------------------------------
    int numSquares(int n) {
        vector<int> ps = perfectSq(n);
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = INT_MAX;
            for(int p : ps){
                if(p <= i) {
                    int res = dp[i-p];
                    if(res != INT_MAX) {
                        dp[i] = min(dp[i], 1 + res);
                    }
                }
            }

        }
        return dp[n];
        // return solve(n,0,ps,dp);
    }
};