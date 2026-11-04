class Solution {
public:
    int helper(int n,vector<int> &dp){
        if (n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int total = 0;
        for(int i =1; i <=n;i++ ){
            int leftST = helper(i-1,dp);
            int rightST = helper(n-i,dp);
            total += leftST * rightST; 

        }
        return dp[n]=total;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};