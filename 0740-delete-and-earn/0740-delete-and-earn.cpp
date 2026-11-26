class Solution {
public:
   
    // int solve(int v ,vector<int> &points,vector<int> &dp){
    //     if (v <= 0) return 0;
    //     if(dp[v]!=-1){
    //         return dp[v];
    //     }
    //     int skip = solve(v - 1, points,dp);
    //     int take = points[v] + solve(v - 2, points,dp);

    //     return dp[v]=max(skip, take);
    // }
    int deleteAndEarn(vector<int>& nums){
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        vector<int> dp(maxVal+1,0);
        for (int x : nums) {
            points[x] += x;
        }
        for (int v = 0; v <= maxVal; ++v) {
            if (v == 0) {
                dp[0] = 0;
            } else if (v == 1) {
                dp[1] = points[1];
            } else {
                int skip = dp[v - 1];
                int take = points[v] + dp[v - 2];
                dp[v] = max(skip, take);
            }
        }

        return dp[maxVal];
        // return solve(maxVal,points,dp);      
    }
};