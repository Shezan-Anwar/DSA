class Solution {
public:
    // int solve(int i , int prev, vector<int> &nums){
    //     if(i==nums.size()){
    //         return 0;
    //     }
    //     int best = solve(i+1,prev,nums);

    //     if(prev == -1 || nums[i]==prev+1){
    //         best = max(best,1 + solve(i+1,nums[i],nums));
    //     }
    //     if(prev == -1 || nums[i]+1==prev+1){
    //         best = max(best,1 + solve(i+1,nums[i]+1,nums));
    //     }  
    //     return best;      
    // }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<int> dp(nums.size(),-1);

        // return solve(0,-1,nums);
        unordered_map<int, int> dp;
        int ans = 0;

        for (int v : nums) {
            dp[v + 1] = max(dp[v + 1], dp[v] + 1);
            ans = max(ans, dp[v + 1]);

            dp[v] = max(dp[v], dp[v - 1] + 1);
            ans = max(ans, dp[v]);
        }

        return ans;
    }
};