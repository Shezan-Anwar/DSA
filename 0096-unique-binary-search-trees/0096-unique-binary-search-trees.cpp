class Solution {
public:
// ------------------memoization-------------------------
    // int helper(int n,vector<int> &dp){
    //     if (n==0 || n==1){
    //         return 1;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int total = 0;
    //     for(int i =1; i <=n;i++ ){
    //         int leftST = helper(i-1,dp);
    //         int rightST = helper(n-i,dp);
    //         total += leftST * rightST; 

    //     }
    //     return dp[n]=total;
    // }
//----------------------------------------------------------------

    int numTrees(int n) {
        vector<int> dp(n+1,0);
        if(n==1) return 1;
        dp[0]=1;
        dp[1]=1;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
            
        }
        return dp[n];
        // return helper(n,dp);
    }
};