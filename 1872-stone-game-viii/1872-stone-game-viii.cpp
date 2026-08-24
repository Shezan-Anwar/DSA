class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n,0);
        dp[0]=stones[0];
        for(int i = 1; i < n ; i++){
            dp[i]=dp[i-1]+stones[i];
        }
        int ans = dp[n-1];
        for(int i = n-2;i>=1;i--){
            ans = max(ans,dp[i]-ans);
        }
        return ans;
    }
};