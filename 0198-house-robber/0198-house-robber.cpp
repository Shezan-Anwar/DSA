class Solution {
public:
    int helper(vector<int>& nums , int i , vector<int>& dp){
        if(i<0) return 0 ; 
        if(i == 0) return nums[0]; 
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + helper(nums,i-2,dp);
        int leave = helper(nums,i-1,dp);

        return dp[i]= max(pick,leave);

        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n,-1);
        return helper(nums,n-1,dp);
    }
};