class Solution {
public:
    // void helper(vector<vector<int>>& dungeon,int i ,int j , vector<vector<int>> &dp , int &n,int &minHealth){
        
    //     if(i<0 || i>=n || j<0 || j>=n){
    //         return;
    //     }

    //     if(dp[i][j]!=INT_MAX){
    //         return dp[i][j];
    //     }
        
    // }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1));
        // last place me health init;
        dp[n-1][m-1] = max(1,1-dungeon[n-1][m-1]);
        // setting the last columnn kyuki unke paas sif ek move h;
        for(int i = m-2;i>=0;i--){
            
            dp[n-1][i]=max(1,dp[n-1][i+1]-dungeon[n-1][i]);

        }
        for(int i = n-2;i>=0;i--){
            dp[i][m-1]=max(1,dp[i+1][m-1]-dungeon[i][m-1]);
            

        }



        //ab beech wale jinke paas 2 moves h unka calculation;
        for(int i = n-2;i>=0;i--){
            for(int j = m-2;j>=0;j--){
                dp[i][j]=max(1,min(dp[i][j+1],dp[i+1][j])-dungeon[i][j]);
            }
        }
        return dp[0][0];
        //dp[i][j] represents the min health require to reach to the destination from that dp[i][j] point;

    }
};