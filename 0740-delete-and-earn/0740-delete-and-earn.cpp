class Solution {
public:
    int n = 0;
    int solve(int v ,vector<int> &points,vector<int> &dp){
        if (v <= 0) return 0;
        if(dp[v]!=-1){
            return dp[v];
        }
        int skip = solve(v - 1, points,dp);
        int take = points[v] + solve(v - 2, points,dp);

        return dp[v]=max(skip, take);
    }
    int deleteAndEarn(vector<int>& nums){
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        vector<int> dp(maxVal+1,-1);
        for (int x : nums) {
            points[x] += x;
        }
        return solve(maxVal,points,dp);      
    }
};